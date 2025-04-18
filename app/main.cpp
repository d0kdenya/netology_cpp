#include <iostream>
#include <vector>
#include <limits>
#include <memory>
#include "Race.h"
#include "factory.h"
#include "exceptions.h"

static int askInt(const std::string& prompt,int min,int max)
{
    int v;
    while(true){
        std::cout<<prompt;
        if(std::cin>>v && v>=min && v<=max) return v;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Некорректный ввод!\n";
    }
}

static double askDouble(const std::string& p)
{
    double d;
    while(true){
        std::cout<<p;
        if(std::cin>>d && d>0) return d;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Некорректно!\n";
    }
}

int main(){
    system("chcp 65001 > nul");

    while(true){
        std::cout<<"Добро пожаловать в гонки!\n"
                 <<"1. Наземная\n2. Воздушная\n3. Смешанная\n";
        int type=askInt("Выберите: ",1,3);
        RaceType rtype = type==1?RaceType::Land:type==2?RaceType::Air:RaceType::Mixed;
        double dist = askDouble("Введите дистанцию: ");

        Race race(rtype,dist);
        auto names = listAllNames();

        while(true){
            std::cout<<"\nДолжно быть >=2 ТС\n1. Зарегистрировать\n2. Начать гонку\n";
            int act = askInt("Выберите: ",1,2);
            if(act==2){
                if(const_cast<Race&>(race).start().size()<2){
                    std::cout<<"Мало участников!\n";
                    continue;
                }
                break;
            }
            std::cout<<"\nСписок ТС:\n";
            for(size_t i=0;i<names.size();++i)
                std::cout<<i+1<<". "<<names[i]<<'\n';
            int idx=askInt("Выберите или 0 для отмены: ",0,(int)names.size());
            if(idx==0) continue; --idx;
            try{
                if(rtype==RaceType::Land&& !isLand(idx))throw RegistrationError("Это не наземный транспорт!");
                if(rtype==RaceType::Air && !isAir(idx)) throw RegistrationError("Это не воздушный транспорт!");
                race.registerTransport(createByIndex(idx));
                std::cout<<names[idx]<<" зарегистрирован!\n";
            }catch(const RegistrationError& e){ std::cout<<e.what()<<'\n';}
        }

        try{
            auto res = race.start();
            std::cout<<"\nРезультаты:\n";
            int pos=1;
            for(auto& p:res)
                std::cout<<pos++<<". "<<p.first<<". Время: "<<p.second<<'\n';
        }catch(const std::exception& e){ std::cout<<e.what()<<'\n'; }

        int again=askInt("\n1. Ещё гонку\n2. Выход\n",1,2);
        if(again==2) break;
    }
}