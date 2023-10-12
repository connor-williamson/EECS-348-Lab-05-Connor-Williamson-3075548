#include <stdio.h>
#include <string.h>


void printSalesReport(double sales[], char* months[]) 

{

    printf("Monthly sales report for 2022:\n\n");
    printf("Month      Sales\n\n");
    
    for (int i = 0; i < 12; i++) 
    
    {
    
        printf("%-10s $%.2f\n", months[i], sales[i]);
        
    }
    
}

void printSalesSummary(double sales[], char* months[]) 

{

    double min = sales[0];
    double max = sales[0];
    double total = 0;

    int minMonth = 0;
    int maxMonth = 0;

    for (int i = 0; i < 12; i++) 
    
    {
    
        if (sales[i] < min) 
        
        {
        
            min = sales[i];
            minMonth = i;
            
        }
        
        if (sales[i] > max) 
        
        {
        
            max = sales[i];
            maxMonth = i;
            
        }
        
        total += sales[i];
        
    }

    double average = total / 12;

    printf("\n\nSales summary:\n\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Average sales: $%.2f\n", average);
    
}

void printSixMonthMovingAverage(double sales[], char* months[]) 

{

    printf("\n\nSix-Month Moving Average Report:\n\n");
    
    for (int i = 0; i < 7; i++) 
    
    {
    
        double sum = 0;
        for (int j = i; j < i + 6; j++) 
        
        {
        
            sum += sales[j];
            
        }
        
        printf("%s - %s $%.2f\n", months[i], months[i + 5], sum / 6);
        
    }
    
}

void bubbleSort(double arr[], char* months[], int n) 

{

    int i, j;
    double temp;
    char* temp_month;
    int swapped;

    for (i = 0; i < n - 1; i++) 
    
    {

        swapped = 0;
        
        for (j = 0; j < n - i - 1; j++) 
        
        {
        
            if (arr[j] < arr[j + 1]) 
            
            { 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                temp_month = months[j];
                months[j] = months[j + 1];
                months[j + 1] = temp_month;

                swapped = 1;
            }
            
        }

        if (swapped == 0) 
        
        {
        
            break;
            
        }
        
    }
    
}

void printSalesReportDescending(double sales[], char* months[], int n)

{

    bubbleSort(sales, months, n);
    printf("\n\nSales Report (Highest to Lowest):\n\n");
    printf("Month      Sales\n\n");
    
    for (int i = 0; i < n; i++) 
    
    {
    
        printf("%-10s $%.2f\n", months[i], sales[i]);
        
    }
    
}

int main() 

{

    double sales[] = 
    
    {
    	23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22,
    	72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22     
    };
    
    char *months[] = 
    
    {
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
    };
    
    int n = sizeof(sales) / sizeof(sales[0]);

    printSalesReport(sales, months);
    printSalesSummary(sales, months);
    printSixMonthMovingAverage(sales, months);
    printSalesReportDescending(sales, months, n);

    return 0;
    
}
