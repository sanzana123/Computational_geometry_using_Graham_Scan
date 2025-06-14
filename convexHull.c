#include <stdio.h>
#include <string.h>
#define MAX 100
#define RANDOM 1000
#include <stdlib.h>  
#include <time.h>
#include <math.h>

//counterclockwise = 1;
//clockwise = 2;
//collinear = 0;

struct Points{
        int x;
        int y;
};
/*float dist(struct Points p1, struct Points p2){
        return sqrt((p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x));
}*/
int orientation(struct Points p, struct Points q, struct Points r){  
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
        
        if (val>0){
             return 2;   
        }
        else if (val<0){
                return 1;
        }
        else {
                return 0;
        }
} //Time Complexity of orientation function = O(1)


void convexHull(struct Points coordinates[], int countofPoints){
        struct Points hull_array[countofPoints];
        FILE* convexHullFile;
        convexHullFile=fopen("convext.txt", "w+");
        int topmostPoint=0;
        int hull_index=0;
        for (int j=1; j<countofPoints; j++){   //O(countofPoints) = The first point in the coordinate array is considered to be the minimum. That point is checked against each and every point of the array creating a Time complexity of O(N)
                if(coordinates[j].y<coordinates[topmostPoint].y) //O(1) = Constant operation of just updating the index of the topmost points
                {
                        topmostPoint=j;
                        
                }
                if (coordinates[j].y==coordinates[topmostPoint].y) //O(1) = Constnt Operation because it only updates the point based on their x corrdinte given  that the y coordinate is the same
                {
                        if (coordinates[j].x <= coordinates[topmostPoint].x){
                                topmostPoint=j; //Jarvis's Merch Special case- Finds the topmost point because that is guranteed to be on the hull
                                        
                        }
                                
                }
                
        }
        hull_array[hull_index]=coordinates[topmostPoint]; ///
        int p=topmostPoint, nextCandidatePoint;
        do{                                               
                
                nextCandidatePoint=(p+1)%countofPoints;
                for(int k=0; k<countofPoints; k++){
                        
                         
                        if ((orientation(coordinates[p], coordinates[nextCandidatePoint], coordinates[k]) == 2))
                        {
                                nextCandidatePoint=k;
                                
                        }
                        
                }
                hull_index++; //O(1)
                hull_array[hull_index]=coordinates[nextCandidatePoint]; //O(1)
                p=nextCandidatePoint; //O(1)
        }while(p != topmostPoint);  //O(count of Points) * O(convexHullPoints) = O(count of Points * convexHullPoints)
        
        printf("Hull points are: ");
        printf("\n");
        fprintf(convexHullFile, "%d\n", hull_index);
        if (convexHullFile != NULL){
                printf("%d\n", hull_index);
            for (int m=1; m<=hull_index; m++) {  //O(hull_index)
                printf("\n(%d %d)\n", hull_array[m].x, hull_array[m].y);
                fprintf(convexHullFile, "%d %d\n", hull_array[m].x, hull_array[m].y);
            }
        }
        fclose(convexHullFile);

} //Total Time Complexity of convexHull function = O(count of Points) * O(convexHullPoints) + O(hull_index)= O(count of Points * convexHullPoints)

int main(void)
{
        FILE *fp1;  //O(1)
        int count;  //O(1)
        int x, y;   //O(1)
        int rx, ry;  //O(1)
        
        srand(time(NULL));  //O(1)
        
        fp1=fopen("file.txt", "w+"); //O(1)
        
        fprintf(fp1, "%d\n", RANDOM); //O(1)
       
        for (int i=0; i<(RANDOM); i++){ //O(RANDOM)
                rx=rand()%RANDOM;
                ry=rand()%RANDOM;
                
                fprintf(fp1, "%d %d\n", rx, ry);
        }
        rewind(fp1);  //O(1), //After writing to the file, rewind moves the filepointer back to the top to start reading
        fp1=fopen("file.txt", "r+");
        if (fp1==NULL)  //O(1)
        {
                printf("The file did not open");
                return 1;
        }
        fscanf(fp1, "%d", &count); //O(1)
        printf("%d\n", count);     //O(1)

        struct Points coordinates[count]; //O(1), //array of structs, coordinates={(0, 0), (1,2), (3,4), (5, 6)}
        int buffer[count];
        
        for (int i=0; i<count; i++)  //O(count)
        {
                //Check if fscanf read two integers from the file 
                if (fscanf(fp1, "%d %d", &coordinates[i].x, &coordinates[i].y)==2){
                      printf("(%d %d)\n",coordinates[i].x, coordinates[i].y);
                }
                else{
                        break;
                }
        }
        fclose(fp1);
        
        convexHull(coordinates, count); //O(count * convexHullPoints)
        return 0;
        //RANDOM=count
} //Time Complexity of Main Function = O(count) + O(count * convexHullPoints) + O(count) = O(count*convexHullPoints)