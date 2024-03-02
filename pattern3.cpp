#include<iostream>
using namespace std;
void pattern3(void)
{
    int n;
  cin>>n;
  int row=1;
  while(row<=n)
  {
    int col=1;
    while(col<=n)
    {
        cout<<col;
        col++;
    }
    cout<<endl;
    row++;
  }
}
void pattern4(void)
{
 int n;
  cin>>n;
  int row=1;
  while(row<=n)
  {
    int col=1;
    while(col<=n)
    {
        cout<<(n-col+1);
        col++;
    }
    cout<<endl;
    row++;
  }
}
void pattern5(void)
{
    int n;
  cin>>n;
  int row=1;
   int count=1;
  while(row<=n)
  {
    int col=1;
   
    while(col<=n)
    {
        cout<<count;
        col++;
        count=count+1;
        
    } 
    cout<<endl;
    row++;
  }
}
void pattern6(void)
{
   
    int n;
  cin>>n;
  int row=1;
  while(row<=n)
  {
    int col=1;
    while(col<=row)
    {
        cout<<row;
        col++;
    }
    cout<<endl;
    row++;
  } 
}
void pattern7(void)
{

     int n;
  cin>>n;
  int row=1;
   int count=1;
  while(row<=n)
  {
    int col=1;
   
    while(col<=row)
    {
        cout<<count;
        col++;
        count=count+1;
        
    } 
    cout<<endl;
    row++;
  }
   
}
void pattern8(void)
{
  int n;
  cin>>n;
  int row=1;
   
  while(row<=n)
  {
    int col=1;
   int value=row;
    while(col<=row)
    {
        cout<<value;
        
        value=value+1;
        col++;
        
    } 
    cout<<endl;
    row++;
  }

}void pattern9(void)
{


     int n;
  cin>>n;
  int row=1;
   
  while(row<=n)
  {
    int col=1;
   
    while(col<=row)
    {
        cout<<(row-col+1);
        col++;
       
        
    } 
    cout<<endl;
    row++;
  }
}
void p10()
{
      int n;
  cin>>n;
  int row=1;
  while(row<=n)
  {
    int col=1;
    while(col<=n)
    { char ch=('A'+row-1);
        cout<<ch;
        col++;
    }
    cout<<endl;
    row++;
  }
}
void p11(void)
{
     int n;
  cin>>n;
  int row=1;
  char start='A';
  while(row<=n)
  {
    int col=1;
    while(col<=n)
    { 
        cout<<start;
        col++;
        start=start+1;
        
    }
    cout<<endl;
    row++;
  }
}
void p12()
{
 int n;
  cin>>n;
  int row=1;
  while(row<=n)
  {
    int col=1;
    while(col<=n)
    { char ch=('A'+row+col-2);
        cout<<ch;
        col++;
    }
    cout<<endl;
    row++;
  }
}
void p13()
{
    
     int n;
  cin>>n;
  int row=1;
  char start='A';
  while(row<=n)
  {
    int col=1;
    while(col<=row)
    { 
        cout<<start;
        col++;
        start=start+1;
        
    }
    cout<<endl;
    row++;
  }
}
void p14()
{
     int n;
  cin>>n;
  int row=1;
  
  while(row<=n)
  {
    int col=1;
    char start=('A'+n-row);
    while(col<=row)
    { 
        cout<<start;
        col++;
        start=start+1;
        
    }
    cout<<endl;
    row++;
  }
}
void p15()
{
      
     int n;
  cin>>n;
  int row=1;
  
  while(row<=n)
  {
    int col=1;
     char start=('A'+row-1);
    while(col<=n)
    {
        cout<<start;
        col++;
        start=start+1;
        
    }
    cout<<endl;
    row++;
  }
}
void p16()
{
      
     int n;
  cin>>n;
  int row=1;
  
  while(row<=n)
  {
    int star=(n-row+1);
    while(star)
    {
        cout<<"*";
        star=star-1;
    }
    int col=1;
    while(col<=row)
    {  cout<<" ";
        col++; 
    }
    cout<<endl;
    row++;
  }
}
void p17()
{
  
    int n;
    cin >> n;

    int row = 1;

    while (row <= n) {
        
    int col=1;

        // Print spaces before the numbers
        int space = 1;
        while (space < row) {
            cout << " ";
            space++;
           col++; 
        }

        // Print the numbers
        while (col<=n) {
            cout << row;
          
        col++;
        }

        cout << endl;
 
        row++;
        
    }

   

}
void p18()
{
  

int n;
cin>>n;
int row=1;

while(row<=n)
{int count=row;
	int space = n- row;
	
	while(space)
	{
		cout<<" ";
		space--;
	}
	int col=1;
    
	while(col<=row)
	{
		cout<<count;
		col++;
		count++;

	
	}
	cout<<endl;
	row++;

}

}
void p19()
{

int n;
    cin >> n;

    int row = 1;

    while (row <= n) {
        int count=1;
    int col=1;

        // Print spaces before the numbers
        int space = 1;
        while (space < row) {
            cout << " ";
            space++;
           col++; 
           count++;
        }

        // Print the numbers
        while (col<=n) {
            cout << count;
          
        col++;
        count++;
        }

        cout << endl;
 
        row++;
        
    }

}
void p20()
{
  
    int n = 4; // Change this value to adjust the number of rows
    int row = 1;

    while (row <= n) {
        int space = 1;

        // Print spaces
        while (space <= n - row) {
            cout << " ";
            space++;
        }

        int col = 1;

        // Print increasing numbers
        while (col <= row) {
            cout << col;
            col++;
        }

        col = row - 1;

        // Print decreasing numbers
        while (col >= 1) {
            cout << col;
            col--;
        }

        cout << endl;
        row++;
    }

 

}

int main()
{
 
 p20();
 return 0;


}
