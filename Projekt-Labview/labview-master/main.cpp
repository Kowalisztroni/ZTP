#include "Concatenate.h"
#include "DynamicModuleLink.h"
#include "HelloSource.h"
#include "LabView.h"
#include "Module.h"
#include "ModuleFactory.h"
#include "ModuleLink.h"
#include "NormalCoutSink.h"
#include "WorldSource.h"
#include <algorithm>
#include <iostream>
#include <memory>

void test1()
{
	HelloSource hs;
	std::cout << hs.execute() << std::endl;
	
	Signal result = hs.getResult();
	std::cout << result << std::endl;
	
	NormalCoutSink ncs {1};
	
	std::cout << ncs.execute() << std::endl;
	
	ncs.setInput(result, 0);
	std::cout << ncs.execute() << std::endl;
}

void test2()
{
	HelloSource src_h;
	WorldSource src_w;
	Concatenate tra_c {2};
	NormalCoutSink sin_n {1};
	
	src_h.execute();
	src_w.execute();
	
	tra_c.setInput(src_h.getResult(), 0);
	tra_c.setInput(src_w.getResult(), 1);
	tra_c.execute();
	
	sin_n.setInput(tra_c.getResult(), 0);
	sin_n.execute();
}

std::string to_string(const ModuleState & state)
{
	switch (state)
	{
		case ModuleState::BLOCKED: return "BLOCKED";
		case ModuleState::READY: return "READY";
		case ModuleState::ERROR: return "ERROR";
		case ModuleState::DONE: return "DONE";
	}
	return "UNKNOWN STATE";
}

void test3()
{	
	// ModuleLink musi mieć świadomość co jest źródłem a co celem
	// dlatego mam trzy osobne mapy - bez tego musiałbym uzywać dynamic_cast-a...
	
	std::map<std::string, std::shared_ptr<IModule>> modules;	// all modules
	std::map<std::string, std::shared_ptr<ISource>> sources;	// sources + translates
	std::map<std::string, std::shared_ptr<ISink>> sinks;		// translates + sinks
	
	modules["foo"] = nullptr;
	
	
	// helper variables
	std::shared_ptr<IModule> mod;
	std::shared_ptr<ISource> src;
	std::shared_ptr<ISink> dst;
	std::shared_ptr<ITransform> trm;
	
	src = std::make_shared<HelloSource>();
	modules.insert_or_assign("hello", src);
	sources.insert_or_assign("hello", src);
	
	src = std::make_shared<WorldSource>();
	modules.insert_or_assign("world", src);
	sources.insert_or_assign("world", src);
	
	trm = std::make_shared<Concatenate>(2);
	// mimo iż klasy w hierarchii to czyste interfejsy - tu mamy "diamond problem" przy upcastingu
	// obchodzimy wskazując "ścieżkę" castowania - obojętne, czy wskażemy ISource czy ISink
 	modules.insert_or_assign("concat", std::static_pointer_cast<ISource>(trm));
	sources.insert_or_assign("concat", trm);
	sinks.insert_or_assign("concat", trm);
	
	dst = std::make_shared<NormalCoutSink>(1);
	modules.insert_or_assign("cout", dst);
	sinks.insert_or_assign("cout", dst);
	
	mod = std::make_shared<ModuleLink>(sources["hello"], sinks["concat"], 0);
	modules.insert_or_assign("link1", mod);
	mod = std::make_shared<ModuleLink>(sources["world"], sinks["concat"], 1);
	modules.insert_or_assign("link2", mod);
	mod = std::make_shared<ModuleLink>(sources["concat"], sinks["cout"], 0);
	modules.insert_or_assign("link3", mod);
	
	bool done = false;
	
	do {
		std::for_each(begin(modules), end(modules), [](auto m) 
		{ 
			// std::cout << m.first << " --> " << to_string(m.second->getState()) << std::endl;  
			m.second->execute(); 
		} );
		
		done = std::all_of(begin(modules), end(modules), [] (auto m) 
			{ return m.second->getState() == ModuleState::DONE; });
	} while (not done);
}

void test4()
{
	// wersja z dynamic_cast jest zdecydowanie ładniejsza
	std::map<std::string, std::shared_ptr<IModule>> modules;	// all modules
	
	// helper variables
	std::shared_ptr<IModule> mod;
	
	mod = std::make_shared<HelloSource>();
	modules.insert_or_assign("hello", mod);
	
	mod = std::make_shared<WorldSource>();
	modules.insert_or_assign("world", mod);
	
	// mimo iż klasy w hierarchii to czyste interfejsy - tu mamy "diamond problem" przy upcastingu
	// obchodzimy wskazując "ścieżkę" castowania - obojętne, czy wskażemy ISource czy ISink
	mod = std::static_pointer_cast<ISource>(std::make_shared<Concatenate>(2));
 	modules.insert_or_assign("concat", mod);
	
	mod = std::make_shared<NormalCoutSink>(1);
	modules.insert_or_assign("cout", mod);
	
	mod = std::make_shared<DynamicModuleLink>(modules["hello"], modules["concat"], 0);
	modules.insert_or_assign("link1", mod);
	
	mod = std::make_shared<DynamicModuleLink>(modules["world"], modules["concat"], 1);
	modules.insert_or_assign("link2", mod);
	
	mod = std::make_shared<DynamicModuleLink>(modules["concat"], modules["cout"], 0);
	modules.insert_or_assign("link3", mod);
	
	bool done = false;
	bool error = false;
	do {
		std::for_each(begin(modules), end(modules), [](auto m) { m.second->execute(); } );
		
		done = std::all_of(begin(modules), end(modules), [] (auto & m) 
			{ return m.second->getState() == ModuleState::DONE; });
			
		error = std::any_of(begin(modules), end(modules), [] (auto & m) 
			{ return m.second->getState() == ModuleState::ERROR; });
		if (error)
		{
			std::cout << "KABOOM!" << std::endl;
		}
			
	} while (not done and not error);
}

void test5()
{
	LabView lab;
	
	lab.add_module("hello", std::make_shared<HelloSource>() );
	lab.add_module("world", std::make_shared<WorldSource>() );		

	// mimo iż klasy w hierarchii to czyste interfejsy - tu mamy "diamond problem" przy upcastingu
	// obchodzimy wskazując "ścieżkę" castowania - obojętne, czy wskażemy ISource czy ISink
	lab.add_module("concat", std::static_pointer_cast<ISource>(std::make_shared<Concatenate>(2)) );
	
	lab.add_module("cout", std::make_shared<NormalCoutSink>(1) );

	lab.connect("hello", "concat", 0);
	lab.connect("world", "concat", 1);
	lab.connect("concat", "cout", 0);		
	
	lab.run();
}

void test6()
{
	struct ModuleInfo 
	{
		std::string name;
		std::string className;
	};
	
	std::vector<ModuleInfo> modules = {
		{ "hello", "HelloSource" },
		{ "world", "WorldSource" },
		{ "concat", "Concatenate" },
		{ "cout", "NormalCoutSink" },
		{ "cout2", "NormalCoutSink" }
	};
	
	struct LinkInfo {
		std::string src;
		std::string dst;
		int slot;
	};
	
	std::vector<LinkInfo> links { 
		{"hello", "concat", 0},
		{"hello", "cout2", 0},
		{"world", "concat", 1},
		{"concat", "cout", 0}
	};
	
	LabView lab;
	
	for (auto m: modules)
		lab.add_module(m.name, ModuleFactory::getInstance(m.className));
	
	for (auto link: links )
		lab.connect(link.src, link.dst, link.slot);
	
	lab.run();
}

int main() 
{
//	test1();
//	test2();
//	test3();
//	test4();
//	test5();
//	test6();
	
	return 0;
}
