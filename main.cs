using System;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Timers;
namespace Snake{
  class Programm{
    public static void Main(){
      int m=5;
      int x=0;
      int y=0;
      int t;// 1-Up 2-Down 3-Left 4-Right
      ConsoleKeyInfo direct;
      char [,] map = new char [m,m];
      printmap(m,map,x,y);
    }
    public void printmap(int m,char [,] map,int x,int y){
      for(int i=0;i<m;i++){
        for(int z=0;z<m;z++){
          if(i==x&&z==y){
            Console.Write('1');
          }else{
          Console.Write(map[i,z]);
        }
        }
        Console.WriteLine(" ");
      }
    }
    public void move(int x,int y,int t,ConsoleKeyInfo direct,int m){
      if(Console.KeyAvailable){
        direct=Console.ReadKey(true);
        if(direct.Key==ConsoleKey.UpArrow){
          if(y>0){
            y--;
            t=1;
          }
        }
        if(direct.Key==ConsoleKey.DownArrow){
          if(y<m-1){
            y++;
            t=2;
          }
        }
        if(direct.Key==ConsoleKey.LeftArrow){
          if(x>0){
            x--;
            t=3;
          }
        }
        if(direct.Key==ConsoleKey.RightArrow){
          if(x<m-1){
            x++;
            t=4;
          }
        }
      }
    }
  }
}
