/*****************************************************************************#
#                                                                             #
#                                                #   # #### #### ####         #
#    load.h                                      #   # #  # #    #            #
#                                                #   # #### ###  #            #
#    By: Z. Safiy Errahmane                      #   # #    #    #            #
#                                                 ###  #    #### ####         #
#    Created: 2017/12/03 18:05:32 by Z.Safiy                                  #
#    Updated: 2017/12/03 20:09:52 by Z.Safiy                                  #
#                                                                             # 
#*****************************************************************************/

#ifndef LOAD_H
#define LOAD_H value

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define DEF_PATH "defender/"
#define ENE_PATH "enemies/"
#define MOD_PATH "mods/"
#define LVL_PATH "levels/"

#define BUFFSIZE 1024

typedef struct {
	int ship_width;
	int ship_height;
	int path_size;
	int * path_h;
	int * path_v;
	int ship_health;
	float shot_freq;
	int shot_speed;
	int shot_power;
	char shot;
	char ** shape;
}Ship_fs;


void load_defender(/*player_t * defender,*/char * modename);
void load_shipfile(Ship_fs * file,int fd);
char * get_line(char * buffer,int * i);
void parse_line(char * line,char ** buff);
void show_file(Ship_fs * file);




#endif