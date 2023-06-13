#include <ncurses.h>

void cactus1(int x, int y) {
           mvprintw(y-6,x+3,"_");
      	  mvprintw(y-5,x+2,"( )_");
      	 mvprintw(y-4,x+1,"_| | )");
      	mvprintw(y-3,x+0,"( | |/");
      	 mvprintw(y-2,x+1,"\\| |");
      	  mvprintw(y-1,x+2,"| |");
      	  mvprintw(y,  x+2,"| |");
}
void cactus2(int x, int y) {
           mvprintw(y-6,x+3,"_     _");
      	  mvprintw(y-5,x+2,"( )_ _( )");
      	 mvprintw(y-4,x+1,"_| | ) | |_");
      	mvprintw(y-3,x+0,"( |  / \\  | )");
      	 mvprintw(y-2,x+1,"\\  |   |  / ");
      	  mvprintw(y-1,x+2,"| |___| |");
      	  mvprintw(y,  x+2,"| |   | |");
}
void cactus3(int x, int y) {
                 mvprintw(y-6,x+3,"_     _     _");
	        mvprintw(y-5,x+2,"( )_ _( )  _( )_");
	       mvprintw(y-4,x+1,"_| | ) | |_{ | | )");
	      mvprintw(y-3,x+0,"( | |/| | | ) | | |");
	       mvprintw(y-2,x+1,"\\| |  \\| | /\\| | |");
	        mvprintw(y-1,x+2,"| |___| |/__| |/");
	        mvprintw(y,  x+2,"| |   | |   | |");
}
void cactus4(int x, int y) {
	           mvprintw(y-9,x+5,"__");
	       mvprintw(y-8,x+1,"__ (  ) _");
	      mvprintw(y-7,x+0,"(  )|  |( )");
	      mvprintw(y-6,x+0,"|  ||  || |");
	       mvprintw(y-5,x+1,"\\ ||  || |");
	        mvprintw(y-4,x+2,"\\ V  V /");
	         mvprintw(y-3,x+3,"\\    /");
	          mvprintw(y-2,x+4,"|  |");
	          mvprintw(y-1,x+4,"|  |");
	          mvprintw(y,  x+4,"|  |");
}
void cactus5(int x, int y) {
	          mvprintw(y-9,x+4,"__      __");
	       mvprintw(y-8,x+1,"_ (  ) __ (  )_");
	      mvprintw(y-7,x+0,"( )|  ||  ||  | )");
	      mvprintw(y-6,x+0,"| ||  |(  ||  | |");
	      mvprintw(y-5,x+0,"| ||  |/\\ ||  | |");
	      mvprintw(y-4,x+0,"| ||  V /\\ V  V /");
	      mvprintw(y-3,x+0,"\\ V   /  \\    /");
	        mvprintw(y-2,x+2,"\\   |    |  |");
	         mvprintw(y-1,x+3,"|  |____|  |");
	         mvprintw(y,  x+3,"|  |    |  |");
}
void cactus6(int x, int y) {
	          mvprintw(y-9,x+4,"__     _           __");
	       mvprintw(y-8,x+1,"_ (  ) _ ( ) _    __ (  )_");
	      mvprintw(y-7,x+0,"( )|  |( )| |( )  (  )|  | )");
	      mvprintw(y-6,x+0,"| ||  || || || |  |  ||  | |");
	      mvprintw(y-5,x+0,"| ||  || || V /    \\ ||  | |");
	      mvprintw(y-4,x+0,"| ||  V / V  / _()_ \\ V  V /");
	       mvprintw(y-3,x+1,"\\ V   / \\  | ( || ) \\    /");
	        mvprintw(y-2,x+2,"\\   |   | |  \\  /   |  |");
	         mvprintw(y-1,x+3,"|  |___| |___||____|  |");
	         mvprintw(y,  x+3,"|  |   | |   ||    |  |");
}
void bird1(int x, int y) {
           mvprintw(y-7,x+3,"_");
         mvprintw(y-6,x+1,"_/ \\");
        mvprintw(y-5,x+0,"<___ L_____");
            mvprintw(y-4,x+4,"\\      \\___");
             mvprintw(y-3,x+5,"|      /~~");
             mvprintw(y-2,x+5,"|  r~~'");
             mvprintw(y-1,x+5,"| /");
             mvprintw(y  ,x+5,"|/");
}
void bird2(int x, int y) {
           mvprintw(y-7,x+3,"_  |\\");
         mvprintw(y-6,x+1,"_/ \\ | \\");
        mvprintw(y-5,x+0,"<___ L|  \\");
            mvprintw(y-4,x+4,"\\     \\____");
             mvprintw(y-3,x+5,"\\      /~~");
               mvprintw(y-2,x+6,"L~~~~'");
}
void cloud1(int x, int y) {
               mvprintw(y-2,x+7,"_,--*-,");
           mvprintw(y-1,x+3,",--`       `-,");
        mvprintw(y  ,x+0,".-^--____________\\");
}
void star1(int x, int y) {
        mvprintw(y-2,x+2,"|");
        mvprintw(y-1,x,"~~#~~");
        mvprintw(y  ,x+2,"|");
}
void moon1(int x,int y) {
        mvprintw(y-7,x-6,"_");
        mvprintw(y-6,x-6,"\\`-.");
        mvprintw(y-5,x-6," \\  \\");
        mvprintw(y-4,x-6,"  |  |");
        mvprintw(y-3,x-6,"  |  |");
        mvprintw(y-2,x-6," /  /");
        mvprintw(y-1,x-6,"/.-'");
}
void moon2(int x,int y) {
        mvprintw(y-7,x-5,"__");
        mvprintw(y-6,x-5,"`.`-.");
        mvprintw(y-5,x-5," |   \\");
        mvprintw(y-4,x-5," |    |");
        mvprintw(y-3,x-5," |    |");
        mvprintw(y-2,x-5," |   /");
        mvprintw(y-1,x-5,"/_.-'");
}
void moon3(int x,int y) {
              mvprintw(y-7,x-5,"__");
           mvprintw(y-6,x-8,".-`   `.");
          mvprintw(y-5,x-9,"/        \\");
        mvprintw(y-4,x-10,"|          |");
        mvprintw(y-3,x-10,"|          |");
          mvprintw(y-2,x-9,"\\        /");
           mvprintw(y-1,x-8,"'-.__.-'");
}
void dinosaur1(int x, int y){
                 mvprintw(y-8,x-2,"______ ");
                mvprintw(y-7,x-3,"| o  __|");
                mvprintw(y-6,x-3,"|   |~~ ");
               mvprintw(y-5,x-4,"/    |");
        mvprintw(y-4,x-10,",    /     |=J");
        mvprintw(y-3,x-10,"{*--`     /");
          mvprintw(y-2,x-9,"'-._,_.)/");
             mvprintw(y-1,x-6,"|/ L_");
             mvprintw(y  ,x-6,"L");
}

void dinosaur2(int x, int y){
                 mvprintw(y-8,x-2,"______");
                mvprintw(y-7,x-3,"| o  __|");
                mvprintw(y-6,x-3,"|   |~~ ");
               mvprintw(y-5,x-4,"/    |");
        mvprintw(y-4,x-10,",    /     |=J");
        mvprintw(y-3,x-10,"{*--`     /");
          mvprintw(y-2,x-9,"'-._,_.)/");
             mvprintw(y-1,x-6,"L_ \\|");
                 mvprintw(y  ,x-2,"L");
}
void dinosaur3(int x, int y){
        mvprintw(y-4,x-10,",    _____  ______");
        mvprintw(y-3,x-10,"{*--`     L~J o __|");
          mvprintw(y-2,x-9,"\\_,______r~q__|~~");
           mvprintw(y-1,x-8,"L_  |/  L");
               mvprintw(y  ,x-4,"L");
}
void dinosaur4(int x, int y){
        mvprintw(y-4,x-10,",    _____  ______");
        mvprintw(y-3,x-10,"{*--`     L~J o __|");
          mvprintw(y-2,x-9,"\\_,______r~q__|~~");
           mvprintw(y-1,x-8,"|/  *-  L");
           mvprintw(y  ,x-8,"L   ");
}
void dinosaurFail(int x, int y){
                 mvprintw(y-8 ,x-2,"______");
                mvprintw(y-7 ,x-3,"|(o) __|");
                mvprintw(y-6 ,x-3,"|   |~~ ");
               mvprintw(y-5 ,x-4,"/    |");
        mvprintw(y-4 ,x-10,",    /     |=J");
        mvprintw(y-3 ,x-10,"{*--`     /");
          mvprintw(y-2 ,x-9,"'-._,_.)/");
             mvprintw(y-1 ,x-6,"|/ \\|");
             mvprintw(y   ,x-6,"L   L");
}
void dinosaurStand(int x, int y){
                 mvprintw(y-8 ,x-2,"______");
                mvprintw(y-7 ,x-3,"| o  __|");
                mvprintw(y-6 ,x-3,"|   |~~ ");
               mvprintw(y-5 ,x-4,"/    |");
        mvprintw(y-4 ,x-10,",    /     |=J");
        mvprintw(y-3 ,x-10,"{*--`     /");
          mvprintw(y-2 ,x-9,"'-._,_.)/");
             mvprintw(y-1 ,x-6,"|/ \\|");
             mvprintw(y   ,x-6,"L   L");
}
void dirt1(int x,int y) {
        mvprintw(y-1,x-45,"/^\\__/^\\");
        mvprintw(y,x-36,"_");
        mvprintw(y,x-25,".");
        mvprintw(y,x-15,"-");
        mvprintw(y,x-7,"_");
        mvprintw(y,x+2,"-");
        mvprintw(y,x+12,".");
        mvprintw(y,x+21,"_");
        mvprintw(y,x+30,"-");
}
