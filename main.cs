using System;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Timers;
using System.Diagnostics;
namespace Snake{
  class Programm{
    public static void Main(){
      int m=10;
      int [,] ppos = new int [2,m*m];
      int x=0;
      int xeat=0;
      int yeat=0;
      int a=0;
      int b=0;
      int y=0;
      int f=1;
      int t=0;// 1-Up 2-Down 3-Left 4-Right
      char [,] map = new char [m,m];
      while(true){
        fillmap(m,map,ref x,ref y,ref xeat,ref yeat,ref f,ppos,ref a,ref b);
        move(ref x,ref y,ref t,m);
        if(f==1){
        eat(m,ref x,ref y,ref xeat,ref yeat);
        f=0;
        }
        Thread.Sleep(500);
        Console.Clear();
        printmap(m,map);
        if(t==5){
          fail();
          break;
        }
        }
    }
      public static void fail ()
      {
          Console.Clear();
          Console.WriteLine                 ("    #    ##### ###### #####");
          Console.WriteLine                 ("   #    #   # #      #    ");
          Console.WriteLine                 ("  #    #   # ###### #####");
          Console.WriteLine                 (" #    #   #      # #    ");
          Console.WriteLine                 ("#### ##### ###### #####");
      }
      public static void fillmap(int m,char [,] map,ref int x,ref int y,ref int xeat,ref int yeat,ref int f,int [,] ppos,ref int a, ref int b)
      {
        for(int i=0;i<m;i++){
          for(int z=0;z<m;z++){
            if(x==z&&i==y){
              map[i,z]='1';
            }else if(xeat==z&&i==yeat){
              map[i,z]='x';
            }else{
              map[i,z]='0';
              }
            if(x==z&&i==y&&xeat==z&&yeat==i){
              f=1;
            } 
            }
          }
      }
      public static void printmap(int m,char [,] map)
      {
        for(int i=0;i<m;i++){
        for(int z=0;z<m;z++){
          Console.Write(map[i,z]);
        }
        Console.WriteLine(" ");
        }
      }
      public static void move(ref int x,ref int y,ref int t,int m)
      {
        if(Console.KeyAvailable){
          ConsoleKeyInfo direct=Console.ReadKey(true);
          if(direct.Key==ConsoleKey.UpArrow){
            if(y>0){
              y--;
              t=1;
            }else{
              t=5;
            }
          }
          if(direct.Key==ConsoleKey.DownArrow){
            if(y<m-1){
              y++;
              t=2;
            }else{
              t=5;
            }
          }
          if(direct.Key==ConsoleKey.LeftArrow){
            if(x>0){
              x--;
              t=3;
            }else{
              t=5;
            }
          }
          if(direct.Key==ConsoleKey.RightArrow){
            if(x<m-1){
              x++;
              t=4;
            }else{
              t=5;
            }
          }
        }else{
          if(t==1){
            y--;
          }else
          if(t==2){
            y++;
          }else
          if(t==3){
            x--;
          }else
          if(t==4){
            x++;
          }else
          if(t==0){
            x++;
          }
          if(x<0||x>=m||y<0||y>=m){
            t=5;
          }
        }
      }
      public static void eat(int m,ref int x,ref int y,ref int xeat,ref int yeat)
      {
          Random rand = new Random();
          xeat=rand.Next(0,m);
          yeat=rand.Next(0,m);
          if(xeat==x&&yeat==y)
          {
          eat(m,ref x,ref y,ref xeat,ref yeat);
          }
      }
      public static void snake(ref int x,ref int y,int [,] ppos,ref int t,ref int f)
      {
   
        ppos[0,0]=1;

      }
    }
}