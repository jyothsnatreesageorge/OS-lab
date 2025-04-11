#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
        struct dirent* d;
        struct stat s;
        DIR* d1=opendir(".");
        if(d1==NULL)
        {
                printf("Error in opening the diretory!\n");
                exit(0);
        }
        while((d=readdir(d1))!=NULL)
        {
                //printf("Directory name:%s\n",d->d_name);
                if(stat(d->d_name,&s)==0)
                {
                        printf("File Status\nName:%s\nFile Type and mode:%o\nNumber of hard links:%d\n",d->d_name,s.st_mode,s.st_nlink);
                        printf("Size: %ld bytes\n", s.st_size);
                        printf("Owner UID: %d\n", s.st_uid);
                        printf("Group GID: %d\n", s.st_gid);
                        printf("Last access time: %ld\n", s.st_atime);
                        printf("Last modification time: %s\n", ctime(&s.st_mtime));
                        printf("Last status change time: %s\n", ctime(&s.st_ctime));
                        printf("Block size: %ld\n", s.st_blksize);
                        printf("Allocated blocks: %ld\n\n\n", s.st_blocks);
                }

        }
        closedir(d1);
        return 0;
}
