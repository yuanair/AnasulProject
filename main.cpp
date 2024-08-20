
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

#include <thread>
#include <format>
#include <iostream>
#include <fstream>
#include <filesystem>

class MyProgram : public Anasul::Program
{
public:
	
	Anasul::Logger &GetLogger() override
	{
		static Anasul::LoggerFormatterSimple loggerFormatterSimple{};
		static Anasul::LoggerToStream logger{loggerFormatterSimple, std::cout, std::wcout};
		return logger;
	}
	
	void BeginPlay() override
	{
		GetLogger().Log(Anasul::LogLevel::Info, std::format("{} {}", Anasul::GetNameA(), Anasul::GetVersionA()));
		GetLogger().Log(Anasul::LogLevel::Info, std::format(": {}", Anasul::Type::eof));
		GetLogger().Flush();
		
		std::filesystem::current_path(std::filesystem::current_path() / "Data");
		
		std::basic_ifstream<Anasul::chararcter> ifs{"./test.anasul"};
		
		if (!ifs.is_open())
		{
			GetLogger().Log(Anasul::LogLevel::Fatal, "cannot open file");
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
		
		m_window = Anasul::WindowFactory::CreateWindow(Anasul::WindowType::GLFW);
		m_renderer = Anasul::RendererFactory::Create(Anasul::RendererType::OpenGL);
		
		m_window->Create("Anasul", 1280, 720);
		
	}
	
	void Tick() override
	{
		m_window->Update();
	}
	
	void EndPlay() override
	{
		m_window.reset();
		m_renderer.reset();
		GetLogger().Log(Anasul::LogLevel::Info, "EndPlay");
		GetLogger().Flush();
	}

private:
	
	std::unique_ptr<Anasul::Window> m_window;
	std::unique_ptr<Anasul::Renderer> m_renderer;
	
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






























