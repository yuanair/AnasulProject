
//*

#include <Anasul/Program.hpp>
#include <Anasul/Application.hpp>
#include <Anasul/Platform.hpp>
#include <Anasul/Version.hpp>
#include <Anasul/LoggerToStream.hpp>
#include <Anasul/LoggerFormatterSimple.hpp>
#include <Anasul/LexerDefault.hpp>

#include <Anasul/WindowFactory.hpp>
#include <Anasul/RendererFactory.hpp>
#include <Anasul/WindowRenderTarget.hpp>

#include <thread>
#include <format>
#include <iostream>
#include <fstream>
#include <filesystem>

class MyProgram : public Anasul::Program
{
public:
	
	template<typename ElemT>
	std::basic_ifstream<ElemT> Open(const std::filesystem::path &path)
	{
		std::basic_ifstream<ElemT> ifs{path};
		if (!ifs.is_open())
		{
			GetLogger().Log(
				Anasul::LogLevel::Fatal,
				std::format("cannot open file \"{}\"", (path).string())
			);
		}
		return ifs;
	}
	
	Anasul::Logger &GetLogger() override
	{
		static Anasul::LoggerFormatterSimple loggerFormatterSimple{};
		static Anasul::LoggerToStream logger{loggerFormatterSimple, std::cout, std::wcout};
		return logger;
	}
	
	void BeginPlay() override
	{
		
		// 注册启动项
		Anasul::StringW startUpFileName = L"\"" + (std::filesystem::current_path() / "Main.exe").wstring() + L"\"";
		Anasul::StringW buffer;
		if (Anasul::Platform::OnlyInWindows::GetBootStartUp(L"Anasul", buffer))
		{
			if (buffer != startUpFileName)
			{
				GetLogger().Log(Anasul::LogLevel::Error, std::format(TEXT("Error Boot start up: {}"), buffer));
				Anasul::Platform::OnlyInWindows::DeleteBootStartUp(L"Anasul");
			}
			else
			{
				GetLogger().Log(Anasul::LogLevel::Info, std::format(TEXT("Boot start up: {}"), buffer));
			}
		}
		else
		{
			Anasul::Platform::OnlyInWindows::SetBootStartUp(L"Anasul", startUpFileName);
			GetLogger().Log(
				Anasul::LogLevel::Info, std::format(TEXT("Set Boot start up: {}"), startUpFileName));
		}
		
		std::filesystem::current_path(std::filesystem::current_path() / "Data");
		
		std::basic_ifstream<Anasul::chararcter> ifs{
			Open<Anasul::chararcter>(std::filesystem::current_path() / "test.anasul")
		};
		
		if (!ifs.is_open())
		{
			Anasul::Application::Exit();
			return;
		}
		
		Anasul::LexerDefault<Anasul::chararcter> lexer{ifs, GetLogger()};
		
		while (!lexer.IsEnd())
		{
			auto token = lexer.AnalysisNext();
			if (!token) continue;
			GetLogger().Log(Anasul::LogLevel::Info, std::format(TEXT("> {}"), token->ToString()));
		}
		
		ifs.close();
		
		m_window = Anasul::WindowFactory::CreateWindow(Anasul::WindowType::Default, GetLogger());
		
		
		m_renderer = Anasul::RendererFactory::CreateRenderer(Anasul::RendererType::DirectX2D, GetLogger());
		m_dWriteRenderer = Anasul::RendererFactory::CreateTextRenderer(
			Anasul::TextRendererType::DirectWrite, GetLogger());
		
		if (!m_window->Create(
			{"Anasul", 0, 0, INT_MIN, INT_MIN, nullptr, true}
		))
		{
			GetLogger().Log(Anasul::LogLevel::Fatal, TEXT("cannot create window"));
			Anasul::Application::Exit();
			return;
		}
		if (!Anasul::Platform::OnlyInWindows::IsAeroEnabled())
		{
			GetLogger().Log(Anasul::LogLevel::Fatal, TEXT("Aero is not enabled"));
			Anasul::Application::Exit();
			return;
		}
		// Anasul::Platform::OnlyInWindows::RenderToDesktop(m_window.get());
		
		m_window->Notify("???");
		m_window->Show();
		
		m_renderTarget.reset(m_renderer->CreateWindowRenderTarget(*m_window));
		m_font.reset(m_dWriteRenderer->CreateFont(L"Consolas", 16));
	}
	
	void Tick() override
	{
		m_renderTarget->BeginDraw();
		m_renderTarget->Clear(Anasul::Color4f(0.0f, 0.0f, 0.5f, 1.0f));
		Anasul::Point2i mousePos;
		m_window->GetMousePosition(mousePos.x, mousePos.y);
		m_renderTarget->DrawText(
			*m_font,
			"Hello Anasul", Anasul::Rect4f(mousePos.x, mousePos.y, 100.0f, 100.0f),
			Anasul::Color4f(1.0f, 1.0f, 1.0f, 1.0f));
		m_renderTarget->EndDraw();
		m_window->Update();
	}
	
	void EndPlay() override
	{
		m_window.reset();
		m_renderer.reset();
	}

private:
	
	std::unique_ptr<Anasul::Window> m_window;
	std::unique_ptr<Anasul::Renderer> m_renderer;
	std::unique_ptr<Anasul::TextRenderer> m_dWriteRenderer;
	std::unique_ptr<Anasul::WindowRenderTarget> m_renderTarget;
	std::unique_ptr<Anasul::Font> m_font;
	
};

Anasul::Program &AnasulMain()
{
	static MyProgram myProgram;
	return myProgram;
}

#include <Anasul/Main.hpp>

/*/

#include <iostream>
#include <string>


int main() // main是入口函数
{
	
	
	system("pause");
	
	return 0; // 返回0
}

//*/






























