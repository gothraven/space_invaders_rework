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

void load_defender(/*player_t * defender,*/char * modename);




#endif