#include <iostream>
#include <string>
using namespace std;

// class Base {
// 	private:	

// 	public:
//     virtual void method()=0;
// 	protected:

// };

// class Derivate :public Base {
// 	private:
//     public:
//     void method(){
//         cout << "test";
//     }
// };

// int main()
// {   
//     Derivate* derivate = new Derivate();
//     Base* base;

//     base = derivate;
    
//     derivate->method();
//     delete(derivate);
// }


class TapePlayer{
    private:
        string name;
        bool status=false;
    public:
      void Music(){
            if(!status){
                status=true;
                cout <<"Music's playing"<<endl;
            }
            else cout <<"Music's already playing"<<endl;
        };
        TapePlayer(string name){
            this->name=name;
        }
};

class Player{
    public:
        virtual void PlayMusic()=0;
};

class MP3Player:public Player{
    private:
        bool status=false;
    public:
        void PlayMusic(){
            if(!status){
                status=true;
                cout <<"Muzyka startuje"<<endl;
            }
        }
};

class NetPlayer:public Player{    
    private:
        bool status=false;
    public:
        void PlayMusic(){
            if(!status){
                status=true;
                cout <<"Muzyka startuje"<<endl;
            }
        }
    };

class AdapterTapePlayer: public Player{
        private:
        TapePlayer *tapePlayer;
        public:
        void PlayMusic(){
            tapePlayer->Music();
        }
        AdapterTapePlayer(TapePlayer *tapePlayer){
            this->tapePlayer=tapePlayer;
        }
    
    };
int main(){

    Player* player;
    NetPlayer* netPlayer=new NetPlayer;
    MP3Player* mp3Player=new MP3Player;

    TapePlayer* tapePlayer=new TapePlayer("Adam");
    AdapterTapePlayer* adaptertapeplayer = new AdapterTapePlayer(tapePlayer);
    player=netPlayer;
    player->PlayMusic();

    player=mp3Player;
    player->PlayMusic();

    player=adaptertapeplayer;
    player->PlayMusic();

    delete(netPlayer);
    delete(mp3Player);
    delete(tapePlayer);
    delete(adaptertapeplayer);
    return 0;
}