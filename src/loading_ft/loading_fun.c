/*****************************************************************************#
*                                                                             #
*                                                #   # #### #### ####         #
*    loading_fun.c                               #   # #  # #    #            #
*                                                #   # #### ###  #            #
*    By: Z. Safiy Errahmane                      #   # #    #    #            #
*                                                 ###  #    #### ####         #
*    Created: 2017/26/03 03:30:32 by Z.Safiy                                  #
*    Updated: 2017/26/03 03:30:32 by Z.Safiy                                  #
*                                                                             #
******************************************************************************/


#include "load.h"


void load_shipfile(Ship_fs * file,int fd){

	int nread;

	char buffer[BUFFSIZE];
	nread = read(fd,buffer,BUFFSIZE);
	int line = 0;
	int i = 0;
	while(i<nread && line < 9){

		char * tab[200];
		parse_line(get_line(buffer,&i),tab);
		
		if(line == 0){
			file->ship_width = atoi(tab[0]);
			file->ship_height = atoi(tab[1]);
		}

		if(line == 1){
			file->path_size = atoi(tab[0]);
		}	
		if(line == 2){
			file->path_h = malloc(file->path_size*sizeof(int));
			for (int l = 0; l < file->path_size; l++){
				file->path_h[l] = atoi(tab[l]);
			}
		}
		if(line == 3){
			file->path_v = malloc(file->path_size*sizeof(int));
			for (int l = 0; l < file->path_size; l++){
				file->path_v[l] = atoi(tab[l]);
			}
		}
		if(line == 4){  //*- problem -*
			file->ship_health = atoi(tab[0]);
		}
		if(line == 5){
			file->shot_freq = atof(tab[0]);
		}
		if(line == 6){
			file->shot_speed = atoi(tab[0]);
		}
		if(line == 7){
			file->shot_power = atoi(tab[0]);
		}
		if(line == 8){
			file->shot = tab[0][0];
		}

		line++;
	}
	int k = 0;

	file->shape = malloc(file->ship_height*sizeof(char*));
	
	while(i<nread){	
		file->shape[k] = get_line(buffer,&i);
		k++;
	}
	
	file->shape[k] = NULL;

}


char * get_line(char * buffer,int * i){
	
	char * line = malloc(1024*sizeof(char));
	int j = 0;

	while(buffer[*i] != '\n'){
		line[j] = buffer[*i];
		(*i)++; j++;
	}
	
	line[j] = '\0';
	(*i)++;

	return line;
}

void parse_line(char * line,char ** buff){
	
	buff[0] = malloc(sizeof(char*));
	int i = 0, j = 0, k = 0;

	while(line[i] != '\0'){
		while(line[i] == ' '){
			buff[j][k]='\0';
			k=0;
			j++;
			buff[j] = malloc(sizeof(char *));
			i++;	
		}
		buff[j][k] = line[i];
		k++;
		i++;
	}
	j++;
	buff[j] = NULL;
	free(line);
}

void show_file(Ship_fs * file){

	printf("ship_width %d\n",file->ship_width);
	printf("ship_height %d\n",file->ship_height);
	printf("path_size %d\n",file->path_size);
	
	printf("path_h :\n");
	for (int i = 0; i < file->path_size; ++i){
		printf("%d ",file->path_h[i]);
	}
	
	printf("\npath_v :\n");
	for (int i = 0; i < file->path_size; ++i){
		printf("%d ",file->path_v[i]);
	}
	printf("\n");

	printf("ship_health %d\n",file->ship_health);
	printf("shot_freq %f\n",file->shot_freq);
	printf("shot_speed %d\n",file->shot_speed);
	printf("shot_power %d\n",file->shot_power);
	printf("shot (%c)\n",file->shot);

	printf("shape :\n");
	int i = 0;
	while(file->shape[i] != NULL){
		printf("%s\n",file->shape[i]);
		i++;
	}
}