#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("data_onevariable.csv","r");
	int N=50,i=0;
	float x[N],y[N],xbar=0,ybar=0,xybar=0,xsqbar=0,slope;
	while(!feof(fp))
	{
		fscanf(fp,"%f,%f\n",&x[i],&y[i]);
		i++;
	}
	fclose(fp);
	for(i=0; i<N; i++)
	{
		xbar+=x[i];
		ybar+=y[i];
		xybar+=x[i]*y[i];
		xsqbar+=x[i]*x[i];
	}
	xbar/=N;
	ybar/=N;
	xybar/=N;
	xsqbar/=N;
	slope=(xybar-xbar*ybar)/(xsqbar-xbar*xbar);
	printf("Slope is %f\n",slope);
	return 0;
}
