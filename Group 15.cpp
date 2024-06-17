//PET FOOD SALES SYSTEM   GROUP15
//KOHJUNKET 1211210437
//DANIELTANNAILE 1211209005
//ONGLIHENG 1211209085
//LIMLIANGYEA 1211210785

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include<cstring>
#include <ctime>
#include <cstdio>
#include <conio.h>
#include <stdexcept> 
#include<stack>

using namespace std;

const int row = 50;

struct petfood {
    string id;
    string food;
    string type;
    float price;
    int quantity;
};

class PetFood {
public:
    string code;
    string name;
    string petType;
    double price;
    int quantity;
    
};

//Pet food mergesort_function
void merge(petfood arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    petfood* L = new petfood[n1];
    petfood* R = new petfood[n2];
    
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].food <= R[j].food) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    delete[] L;
    delete[] R;
}

void mergeSort(petfood arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

//binary search function
int binarySearch(petfood arr[], int size, const string& id) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid].id == id) {
            return mid;  // Found the id at index mid
        }
        if (arr[mid].id < id) {
            left = mid + 1;  // Search right half
        } else {
            right = mid - 1;  // Search left half
        }
    }
    
    return -1;  // id not found
}

class PetFoodStore {
private:
    vector<PetFood> petFoods;

public:
    void PetOptions() const {
        cout << "\n\t\t\tAvailable Pet Options\n";
        cout << "1. Cat\n";
        cout << "2. Dog\n";
        cout << "3. Bird\n";
    }
    ~PetFoodStore() //destructor
	{
        cout << "\nThank you, have a great day.\n";
    }
};

class admin_main_menu
{
	protected:
		int options;
		string search;
		
	public:
		void set_main_menu()
		{
			cout << "***********************************************" << endl;
			cout<<"------ \t\t  ADMIN MENU\t\t ------"<<endl;
			cout<<"==============================================="<<endl;
			cout<<endl<<"\t    >> [1] EMPLOYEE  <<"<<endl;
			cout<<"\t    >> [2] CUSTOMER <<"<<endl;
			cout<<"\t    >> [3] PET FOODS <<"<<endl;
			cout<<"\t      >> [4] EXIT <<"<<endl;
		}
		
};//end of class main menu
string DogID[row] = {};
string DogFoods[row] = {};
string DogType[row] = {};
float DFPrice[row] = {};
int DFQuantity[row] = {};
string CatID[row] = {};
string CatFoods[row] = {};
string CatType[row] = {};
float CFPrice[row] = {};
int CFQuantity[row] = {};
string BirdID[row] = {};
string BirdFoods[row] = {};
string BirdType[row] = {};
float BFPrice[row] = {};
int BFQuantity[row] = {};

class PetFoods : public admin_main_menu
{
	private:
		string dogfood;
		string dogid;
		string dogtype;
		float dfprice;
		int dfquantity;
		string catid;
		string catfood;
		string cattype;
		float cfprice;
		int cfquantity;
		string birdid;
		string birdfood;
		string birdtype;
		float bfprice;
		int bfquantity;
		
public:
    void petfoods_menu()
    {
	     do
      {
      	system("cls");
        cout << "***********************************************" << endl;
        cout << "------ \t\tANIMALS CATEGORY\t ------" << endl;
        cout << "===============================================" << endl;
       cout<<endl<<"\t>>        [1] Dog           <<"<<endl;
			cout<<"\t>>        [2] Cat           <<"<<endl;
			cout<<"\t>>        [3] Bird          <<"<<endl;
			cout<<"\t>> [4] Return to Admin Menu <<"<<endl;
			cout<<"\t>>        [5] Exit          <<"<<endl;
			cout<<"==============================================="<<endl;
			
			
			cout<<endl<<"Select option >>";
			cin>>options;
			
			switch(options)
			{
				case 1:
					system("cls");
					Dog();
					cin.ignore();
					cin.get();
					system("cls");
					break;
				case 2:
					system("cls");
				    Cat();
					cin.ignore();
					cin.get();
					system("cls");
					break;
				case 3:
					system("cls");
				    Bird();
					cin.ignore();
					cin.get();
					system("cls");
					break;
				case 4:
					return;
				case 5:
					exit(0);
				default:
					cout<<endl<<"Invalid code! Please try again...."<<endl;
					cin.ignore();
					cin.get();
					system("cls");
			}//end of switch
			
		   }while(options !=5);
    }
    void Dog()
    {
    	read_dog_files();
    	do
    	{
    	cout << "***********************************************" << endl;
			cout<<"------ \t\t  DOG FOODS\t\t ------"<<endl;
			cout<<"==============================================="<<endl;
			cout<<endl<<"\t    >> [1] Add Records  <<"<<endl;
			cout<<"\t   >> [2] Update Records <<"<<endl;
			cout<<"\t   >> [3] Delete Records <<"<<endl;
			cout<<"\t   >> [4] Search Records <<"<<endl;
			cout<<"\t>> [5] Display All Records <<"<<endl;
			cout<<"\t>> [6] Return to Animals Category <<"<<endl;
			cout<<"\t       >> [7] Exit <<"<<endl;
			cout<<"==============================================="<<endl;
			cout<<"Select options: ";
			cin>>options;
			switch(options)
			{
				case 1:
					Dog_Add_Records();
					save_dog_files();
					system("cls");
					break;
				case 2:
					cin.ignore();
					cout<<"Search by ID >>";
					getline(cin,search);
					Dog_Update_Records();
					save_dog_files();
					system("cls");
					break;
				case 3:
					cin.ignore();
					cout<<endl<<"Delete by ID >>";
					getline(cin,search);
					Dog_Delete_Records();
					save_dog_files();
					system("cls");
					break;
			    case 4:
			    	cin.ignore();
					Dog_Search_Records();
					cin.ignore();
					system("cls");
					break;
				case 5:
					system("cls");
					Dog_Display_Records();
					cin.ignore();
					cin.get();
					system("cls");
					break;	
				case 6:
					return;
				case 7:
					exit(0);
				default:
					cout<<endl<<"Invalid code! Please try again...."<<endl;
					cin.ignore();
					cin.get();
                    system("cls");
			}
			
		   }while(options !=7);
	    }
	    
	void Dog_Add_Records()
	{
		cin.ignore();
	cout<<endl<<"Food ID :";
	getline(cin,dogid);
	cout<<"Food Name :";
	getline(cin,dogfood);
		cout<<"Food Type :";
	getline(cin,dogtype);
	cout<<"Food Price :";
	cin>>dfprice;
	cout<<"Food Quantity :";
	cin>>dfquantity;
	
	for(int i=0;i<row;i++)
	{
		if(DogID[i].empty())
		{
			DogID[i] = dogid;
			DogFoods[i] = dogfood;
			DogType[i] = dogtype;
			DFPrice[i] = dfprice;
			DFQuantity[i] = dfquantity;
			
			cout<<endl<<"Successful Added!"<<endl;
			cin.ignore();
			cin.get();
			break;
		}//If EmpID array is empty, it means that this slot is available for a new DOG record
	}
	}
    
    void Dog_Update_Records()
    {
    		int count=0;
	for(int i=0;i<row;i++)
	{
		if(DogID[i] == search)
		{
			count++;
			
	    cout<<"Food Price :";
	    cin>>dfprice;
	    cout<<"Fodd Quantity:";
	    cin>>dfquantity;
	    
	    DFPrice[i] = dfprice;
	    DFQuantity[i] += dfquantity;
	    
	    cin.ignore();
	    cout<<endl<<"Successfull Updated!"<<endl;
	    cin.get();
	    break;
		}
	}
	if(count == 0)
	{
		cout<<endl<<"Name does'nt exist!"<<endl;
		cin.get();
	}
	}
	
	void Dog_Delete_Records()
{
    int count = 0;

    for (int i = 0; i < row; i++)
    {
        if (DogID[i] == search)
        {
            count++;

            // Shift elements up
            for (int j = i; j < row - 1; j++)
            {
                DogID[j] = DogID[j + 1];
                DogType[j] = DogType[j + 1];
                DogFoods[j] = DogFoods[j + 1];
                DFPrice[j] = DFPrice[j + 1];
                DFQuantity[j] = DFQuantity[j + 1];
            }

            // Clear the last element
            DogID[row - 1] = "";
            DogType[row - 1] = "";
            DogFoods[row - 1] = "";
            DFPrice[row - 1] = 0;
            DFQuantity[row - 1] = 0;

            cout << endl << "Successfully Deleted!" << endl;
            cin.get();

            // Since we shifted elements, we need to decrement `i` to avoid skipping an element
            i--;
        }
    }

    if (count == 0)
    {
        cout << endl << "ID doesn't exist!" << endl;
        cin.get();
    }
}

	
	void Dog_Search_Records() {
    int count = 0;

    // Create a temporary array of petfood structures
    petfood records[row];
    int recordCount = 0;
    for (int i = 0; i < row; i++) {
        if (!DogID[i].empty()) {
            records[recordCount] = {DogID[i], DogFoods[i], DogType[i], DFPrice[i], DFQuantity[i]};
            recordCount++;
        }
    }

    // Sort the temporary records array before performing binary search
    mergeSort(records, 0, recordCount - 1);

    cout << "Search by ID >>";
    getline(cin, search);
    system("cls");

    cout << "" << endl;
    cout << "\t\t\t\t         Current Dog Food" << endl;
    cout << "==================================================================================================================" << endl;

    cout << "No. |     ID      |       Foods                                          |    Type      |   Price  | Quantity  " << endl << "------------------------------------------------------------------------------------------------------------------\n";

    // Perform binary search
    int index = binarySearch(records, recordCount, search);

    if (index != -1) {
        cout << setw(10) << left << (index + 1) << setw(9) << left << records[index].id << setw(55) << left << records[index].food << setw(9) << right << records[index].type << setw(15) << right << fixed << setprecision(1) << records[index].price << setw(8) << records[index].quantity << endl;
    } else {
        cout << "No Record Found!" << endl;
    }

    cout << "--------------------------------------------------" << endl;
}

	
	//Display dog data
	void Dog_Display_Records() {
    petfood records[row];
    int count = 0;
    
    for (int i = 0; i < row; i++) {
        if (!DogID[i].empty()) {
            records[count] = {DogID[i], DogFoods[i], DogType[i], DFPrice[i], DFQuantity[i]};
            count++;
        }
    }

    // Display unsorted data
    cout << "" << endl;
    cout << "\t\t\t\t       Current Unsorted Record" << endl;
    cout << "==================================================================================================================" << endl;
    cout << "No. |     ID      |       Foods                                          |    Type      |   Price  | Quantity  " << endl << "------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << setw(10) << left << (i + 1) << setw(9) << left << records[i].id << setw(55) << left << records[i].food << setw(9) << right << records[i].type << setw(15) << right << fixed << setprecision(1) << records[i].price << setw(8) << records[i].quantity << endl;
    }
    if (count == 0) {
        cout << "No Record found!" << endl;
    }

    // Ask if the user wants to sort the data
    char sortOption;
    cout << "\nDo you want to sort the records? (y/n): ";
    cin >> sortOption;

    if (sortOption == 'y' || sortOption == 'Y') {
        mergeSort(records, 0, count - 1);  // Sort the records by food

        cout << "" << endl;
        cout << "\t\t\t\t         Current Sorted Record" << endl;
        cout << "==================================================================================================================" << endl;
        cout << "No. |     ID      |       Foods                                          |    Type      |   Price  | Quantity  " << endl << "------------------------------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < count; i++) {
            cout << setw(10) << left << (i + 1) << setw(9) << left << records[i].id << setw(55) << left << records[i].food << setw(9) << right << records[i].type << setw(15) << right << fixed << setprecision(1) << records[i].price << setw(8) << records[i].quantity << endl;
        }
    } else {
        cout << "\nReturning to previous menu..." << endl;
    }
}
	
	void read_dog_files()
	{
		int i;
		ifstream read_dog;
		read_dog.open("Dog.txt");
		if(read_dog)
		{
		 
		  for (int i = 0; i < row; i++)
        {
            if (!(read_dog >> DogID[i] >> DogFoods[i] >> DogType[i] >> DFPrice[i] >> DFQuantity[i]))
                break;
        }
		}
		else
		{
			cout<<"File does not exist"<<endl;
			exit(0);
		}
		read_dog.close();
	}
	 
void save_dog_files()
    {
  	    ofstream save_dog;
  	    save_dog.open("Dog.txt");
  	    
  	    if(save_dog)
  	    {
  	    	for(int i=0;i<row;i++)
  	    	{
  	    		if(DogID[i].empty())
  	    		{
  	    			break;
				}
				else
				{
					save_dog << DogID[i] <<" "<< DogFoods[i] <<" "<< DogType[i] <<" "<< DFPrice[i] <<" "<<DFQuantity[i];
				}
			}
		}
		else
		{
			cout<<"File does not exist!"<<endl;
			exit(0);
		}
		save_dog.close();
    }
		
	 void Cat()
    {
    	read_cat_files();
    	do
    	{
    	    cout << "***********************************************" << endl;
			cout<<"------ \t\t  CAT FOODS\t\t ------"<<endl;
			cout<<"==============================================="<<endl;
			cout<<endl<<"\t    >> [1] Add Records  <<"<<endl;
			cout<<"\t   >> [2] Update Records <<"<<endl;
			cout<<"\t   >> [3] Delete Records <<"<<endl;
			cout<<"\t   >> [4] Search Records <<"<<endl;
			cout<<"\t>> [5] Display All Records <<"<<endl;
			cout<<"\t>> [6] Return to Animals Category <<"<<endl;
			cout<<"\t       >> [7] Exit <<"<<endl;
			cout<<"==============================================="<<endl;
			cout<<"Select options: ";
			cin>>options;
			switch(options)
			{
				case 1:
					Cat_Add_Records();
					save_cat_files();
					system("cls");
					break;
				case 2:
					cin.ignore();
					cout<<"Search by ID >>";
					getline(cin,search);
					Cat_Update_Records();
					save_cat_files();
					system("cls");
					break;
				case 3:
					cin.ignore();
					cout<<endl<<"Delete by ID >>";
					getline(cin,search);
					Cat_Delete_Records();
					save_cat_files();
					system("cls");
					break;
			    case 4:
			    	cin.ignore();
					Cat_Search_Records();
					cin.ignore();
					system("cls");
					break;
				case 5:
					system("cls");
					Cat_Display_Records();
					cin.ignore();
					cin.get();
					system("cls");
					break;	
				case 6:
					return;
				case 7:
					exit(0);
				default:
					cout<<endl<<"Invalid code! Please try again...."<<endl;
					cin.ignore();
					cin.get();
                    system("cls");
			}
			
		   }while(options !=7);
	}
	
	void Cat_Add_Records()
	{
	cin.ignore();
	cout<<endl<<"Food ID :";
	getline(cin,catid);
	cout<<"Food Name :";
	getline(cin,catfood);
	cout<<"Food Name :";
	getline(cin,cattype);
	cout<<"Food Price :";
	cin>>cfprice;
	cout<<"Food Quantity :";
	cin>>cfquantity;
	
	for(int i=0;i<row;i++)
	{
		if(CatID[i].empty())
		{
			CatID[i] = catid;
			CatFoods[i] = catfood;
			CatType[i] = cattype;
			CFPrice[i] = cfprice;
			CFQuantity[i] = cfquantity;
			
			cin.ignore();
			cout<<endl<<"Successful Added!"<<endl;
			cin.get();
			break;
		}//If EmpID array is empty, it means that this slot is available for a new employee record
	}
	}
	
	void Cat_Update_Records()
	{
		int count=0;
	for(int i=0;i<row;i++)
	{
		if(CatID[i] == search)
		{
			count++;
			cin.ignore();
	
	    cout<<"Food Price :";
	    cin>>cfprice;
	    cout<<"Food Quantity :";
	    cin>>cfquantity;
	    
	    CFPrice[i] = cfprice;
	    CFQuantity[i] += cfquantity;
	    
	    cin.ignore();
	    cout<<endl<<"Successfull Updated!"<<endl;
	    cin.get();
	    break;
		}
	}
	if(count == 0)
	{
		cout<<endl<<"Name does'nt exist!"<<endl;
		cin.get();
	}
	}
	
	void Cat_Delete_Records()
{
    int count = 0;

    for (int i = 0; i < row; i++)
    {
        if (CatID[i] == search)
        {
            count++;

            // Shift elements up
            for (int j = i; j < row - 1; j++)
            {
                CatID[j] = CatID[j + 1];
                CatType[j] = CatType[j + 1];
                CatFoods[j] = CatFoods[j + 1];
                CFPrice[j] = CFPrice[j + 1];
                CFQuantity[j] = CFQuantity[j + 1];
            }

            // Clear the last element
            CatID[row - 1] = "";
            CatType[row - 1] = "";
            CatFoods[row - 1] = "";
            CFPrice[row - 1] = 0;
            CFQuantity[row - 1] = 0;

            cout << endl << "Successfully Deleted!" << endl;
            cin.get();

            // Since we shifted elements, we need to decrement `i` to avoid skipping an element
            i--;
        }
    }

    if (count == 0)
    {
        cout << endl << "ID doesn't exist!" << endl;
        cin.get();
    }
}
	
	void Cat_Search_Records() {
    int count = 0;

    // Create a temporary array of petfood structures
    petfood records[row];
    int recordCount = 0;
    for (int i = 0; i < row; i++) {
        if (!CatID[i].empty()) {
            records[recordCount] = {CatID[i], CatFoods[i], CatType[i], CFPrice[i], CFQuantity[i]};
            recordCount++;
        }
    }

    // Sort the temporary records array before performing binary search
    mergeSort(records, 0, recordCount - 1);

    cout << "Search by ID >>";
    getline(cin, search);
    system("cls");

    cout << "" << endl;
    cout << "\t\t\t\t         Current Dog Food" << endl;
    cout << "==================================================================================================================" << endl;

    cout << "No. |     ID      |       Foods                                          |    Type      |   Price  | Quantity  " << endl << "------------------------------------------------------------------------------------------------------------------\n";

    // Perform binary search
    int index = binarySearch(records, recordCount, search);

    if (index != -1) {
        cout << setw(10) << left << (index + 1) << setw(9) << left << records[index].id << setw(55) << left << records[index].food << setw(9) << right << records[index].type << setw(15) << right << fixed << setprecision(1) << records[index].price << setw(8) << records[index].quantity << endl;
    } else {
        cout << "No Record Found!" << endl;
    }

    cout << "--------------------------------------------------" << endl;
}
	
	void Cat_Display_Records() {
    petfood records[row];
    int count = 0;
    for (int i = 0; i < row; i++) {
        if (!CatID[i].empty()) {
            records[count] = {CatID[i], CatFoods[i], CatType[i], CFPrice[i], CFQuantity[i]};
            count++;
        }
    }

    // Display unsorted data
    cout << "" << endl;
    cout << "\t\t\t\t       Current Unsorted Record" << endl;
    cout << "==================================================================================================================" << endl;
    cout << "No. |     ID      |       Foods                                          |    Type      |   Price  | Quantity  " << endl << "------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << setw(10) << left << (i + 1) << setw(9) << left << records[i].id << setw(55) << left << records[i].food << setw(9) << right << records[i].type << setw(15) << right << fixed << setprecision(1) << records[i].price << setw(8) << records[i].quantity << endl;
    }
    if (count == 0) {
        cout << "No Record found!" << endl;
    }

    // Ask if the user wants to sort the data
    char sortOption;
    cout << "\nDo you want to sort the records? (y/n): ";
    cin >> sortOption;

    if (sortOption == 'y' || sortOption == 'Y') {
        mergeSort(records, 0, count - 1);  // Sort the records by food

        cout << "" << endl;
        cout << "\t\t\t\t         Current Sorted Record" << endl;
        cout << "==================================================================================================================" << endl;
        cout << "No. |     ID      |       Foods                                          |    Type      |   Price  | Quantity  " << endl << "------------------------------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < count; i++) {
            cout << setw(10) << left << (i + 1) << setw(9) << left << records[i].id << setw(55) << left << records[i].food << setw(9) << right << records[i].type << setw(15) << right << fixed << setprecision(1) << records[i].price << setw(8) << records[i].quantity << endl;
        }
    } else {
        cout << "\nReturning to previous menu..." << endl;
    }
}
	
	void read_cat_files()
	{
		int i;
		ifstream read_cat;
		read_cat.open("Cat.txt");
		if(read_cat)
		{
		 
		  for (int i = 0; i < row; i++)
        {
            if (!(read_cat >> CatID[i] >> CatFoods[i] >> CatType[i] >> CFPrice[i] >> CFQuantity[i]))
                break;
        }
		}
		else
		{
			cout<<"File does not exist"<<endl;
			exit(0);
		}
		read_cat.close();
	}
	 
    void save_cat_files()
    {
  	    ofstream save_cat;
  	    save_cat.open("Cat.txt");
  	    
  	    if(save_cat)
  	    {
  	    	for(int i=0;i<row;i++)
  	    	{
  	    		if(CatID[i].empty())
  	    		{
  	    			break;
				}
				else
				{
					save_cat << CatID[i] <<" "<< CatFoods[i] <<" "<< CatType[i] <<" "<< CFPrice[i] <<" "<< CFQuantity[i];
				}
			}
		}
		else
		{
			cout<<"File does not exist!"<<endl;
			exit(0);
		}
		save_cat.close();
    }
    
	 void Bird()
    {
    	read_bird_files();
    	do
    	{
    	    cout << "***********************************************" << endl;
			cout<<"------ \t\t  BIRD FOODS\t\t ------"<<endl;
			cout<<"==============================================="<<endl;
			cout<<endl<<"\t    >> [1] Add Records  <<"<<endl;
			cout<<"\t   >> [2] Update Records <<"<<endl;
			cout<<"\t   >> [3] Delete Records <<"<<endl;
			cout<<"\t   >> [4] Search Records <<"<<endl;
			cout<<"\t>> [5] Display All Records <<"<<endl;
			cout<<"\t>> [6] Return to Animals Category <<"<<endl;
			cout<<"\t       >> [7] Exit <<"<<endl;
			cout<<"==============================================="<<endl;
			cout<<"Select options: ";
			cin>>options;
			switch(options)
			{
				case 1:
					Bird_Add_Records();
					save_bird_files();
					system("cls");
					break;
				case 2:
					cin.ignore();
					cout<<"Search by ID >>";
					getline(cin,search);
					Bird_Update_Records();
					save_bird_files();
					system("cls");
					break;
				case 3:
					cin.ignore();
					cout<<endl<<"Delete by ID >>";
					getline(cin,search);
					Bird_Delete_Records();
					save_bird_files();
					system("cls");
					break;
			    case 4:
			    	cin.ignore();
					Bird_Search_Records();
					cin.ignore();
					system("cls");
					break;
				case 5:
					system("cls");
					Bird_Display_Records();
					cin.ignore();
					cin.get();
					system("cls");
					break;	
				case 6:
					return;
				case 7:
					exit(0);
				default:
					cout<<endl<<"Invalid code! Please try again...."<<endl;
					cin.ignore();
					cin.get();
                    system("cls");
			}
			
		   }while(options !=7);
	}
	
	Bird_Add_Records()
	{
			cin.ignore();
	cout<<endl<<"Food ID :";
	getline(cin,birdid);		
	cout<<"Food Name :";
	getline(cin,birdfood);
	cout<<"Food Type :";
	getline(cin,birdtype);
	cout<<"Food Price :";
    cin>>bfprice;
	cout<<"Food Quantity :";
    cin>>bfquantity;
    
	for(int i=0;i<row;i++)
	{
		if(BirdID[i].empty())
		{
			BirdID[i] = birdid;
			BirdFoods[i] = birdfood;
			BirdType[i] = birdtype;
			BFPrice[i] = bfprice;
			BFQuantity[i] = bfquantity;
			
			cin.ignore();
			cout<<endl<<"Successful Added!"<<endl;
			cin.get();
			break;
		}//If EmpID array is empty, it means that this slot is available for a new employee record
	}
	}
	
	Bird_Update_Records()//function to update new bird record
	{
		int count=0;
	for(int i=0;i<row;i++)
	{
		if(BirdID[i] == search)
		{
			count++;
		
	    cout<<"Food Price :";
	    cin>>bfprice;
	    cout<<"Food Quantity :";
    	cin>>bfquantity;
	    
	    BFPrice[i] = bfprice;
		BFQuantity[i] += bfquantity; 
	    
	    cin.ignore();
	    cout<<endl<<"Successfull Updated!"<<endl;
	    cin.get();
	    break;
		}
	}
	if(count == 0)
	{
		cout<<endl<<"Name does'nt exist!"<<endl;
		cin.get();
	}
	}
	
	void Bird_Delete_Records()
{
    int count = 0;

    for (int i = 0; i < row; i++)
    {
        if (BirdID[i] == search)
        {
            count++;

            // Shift elements up
            for (int j = i; j < row - 1; j++)
            {
                BirdID[j] = BirdID[j + 1];
                BirdType[j] = BirdType[j + 1];
                BirdFoods[j] = BirdFoods[j + 1];
                BFPrice[j] = BFPrice[j + 1];
                BFQuantity[j] = BFQuantity[j + 1];
            }

            // Clear the last element
            BirdID[row - 1] = "";
            BirdType[row - 1] = "";
            BirdFoods[row - 1] = "";
            BFPrice[row - 1] = 0;
            BFQuantity[row - 1] = 0;

            cout << endl << "Successfully Deleted!" << endl;
            cin.get();

            // Since we shifted elements, we need to decrement `i` to avoid skipping an element
            i--;
        }
    }

    if (count == 0)
    {
        cout << endl << "ID doesn't exist!" << endl;
        cin.get();
    }
}
	
	void Bird_Search_Records() {
    int count = 0;

    // Create a temporary array of petfood structures
    petfood records[row];
    int recordCount = 0;
    for (int i = 0; i < row; i++) {
        if (!BirdID[i].empty()) {
            records[recordCount] = {BirdID[i], BirdFoods[i], BirdType[i], BFPrice[i], BFQuantity[i]};
            recordCount++;
        }
    }

    // Sort the temporary records array before performing binary search
    mergeSort(records, 0, recordCount - 1);

    cout << "Search by ID >>";
    getline(cin, search);
    system("cls");

    cout << "" << endl;
    cout << "\t\t\t\t         Current Dog Food" << endl;
    cout << "==================================================================================================================" << endl;

    cout << "No. |     ID      |       Foods                                          |    Type      |   Price  | Quantity  " << endl << "------------------------------------------------------------------------------------------------------------------\n";

    // Perform binary search
    int index = binarySearch(records, recordCount, search);

    if (index != -1) {
        cout << setw(10) << left << (index + 1) << setw(9) << left << records[index].id << setw(55) << left << records[index].food << setw(9) << right << records[index].type << setw(15) << right << fixed << setprecision(1) << records[index].price << setw(8) << records[index].quantity << endl;
    } else {
        cout << "No Record Found!" << endl;
    }

    cout << "--------------------------------------------------" << endl;
}
	
	void Bird_Display_Records() {
    petfood records[row];
    int count = 0;
    for (int i = 0; i < row; i++) {
        if (!BirdID[i].empty()) {
            records[count] = {BirdID[i], BirdFoods[i], BirdType[i], BFPrice[i], BFQuantity[i]};
            count++;
        }
    }

    // Display unsorted data
    cout << "" << endl;
    cout << "\t\t\t\t       Current Unsorted Record" << endl;
    cout << "==================================================================================================================" << endl;
    cout << "No. |     ID      |       Foods                                          |    Type      |   Price  | Quantity  " << endl << "------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << setw(10) << left << (i + 1) << setw(9) << left << records[i].id << setw(55) << left << records[i].food << setw(9) << right << records[i].type << setw(15) << right << fixed << setprecision(1) << records[i].price << setw(8) << records[i].quantity << endl;
    }
    if (count == 0) {
        cout << "No Record found!" << endl;
    }

    // Ask if the user wants to sort the data
    char sortOption;
    cout << "\nDo you want to sort the records? (y/n): ";
    cin >> sortOption;

    if (sortOption == 'y' || sortOption == 'Y') {
        mergeSort(records, 0, count - 1);  // Sort the records by food

        cout << "" << endl;
        cout << "\t\t\t\t         Current Sorted Record" << endl;
        cout << "==================================================================================================================" << endl;
        cout << "No. |     ID      |       Foods                                          |    Type      |   Price  | Quantity  " << endl << "------------------------------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < count; i++) {
            cout << setw(10) << left << (i + 1) << setw(9) << left << records[i].id << setw(55) << left << records[i].food << setw(9) << right << records[i].type << setw(15) << right << fixed << setprecision(1) << records[i].price << setw(8) << records[i].quantity << endl;
        }
    } else {
        cout << "\nReturning to previous menu..." << endl;
    }
}
	
	void read_bird_files()//function to read file from the Bird.txt file
	{
		int i;
		ifstream read_bird;
		read_bird.open("Bird.txt");
		if(read_bird)
		{
		 
		  for (int i = 0; i < row; i++)
        {
            if (!(read_bird >> BirdID[i] >> BirdFoods[i] >> BirdType[i] >> BFPrice[i] >> BFQuantity[i] ))
                break;
        }
		}
		else
		{
			cout<<"File does not exist"<<endl;
			exit(0);
		}
		read_bird.close();
	}
	 
    void save_bird_files()//function to write bird information to Bird.txt file
    {
  	    ofstream save_bird;
  	    save_bird.open("Bird.txt");
  	    
  	    if(save_bird)
  	    {
  	    	for(int i=0;i<row;i++)
  	    	{
  	    		if(BirdID[i].empty())
  	    		{
  	    			break;
				}
				else
				{
					save_bird << BirdID[i] <<" "<< BirdFoods[i] <<" "<< BirdType[i] <<" "<< BFPrice[i] << " " << BFQuantity;
				}
			}
		}
		else
		{
			cout<<"File does not exist!"<<endl;
			exit(0);
		}
		save_bird.close();
    }
    
};//end of class petfoods_menu

//Structure to hold customer and employee information
struct user {
    string name;
    string password;
};

//selection sort function for employee and customer
void selectionSort(string names[], string passwords[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (names[j] < names[minIndex]) {
                minIndex = j;
            }
        }
        swap(names[i], names[minIndex]);
        swap(passwords[i], passwords[minIndex]);
    }
}

// binary search function for finding an element
int binarySearch(user arr[], int size, const string& name) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].name == name) {
            return mid;  // Found the name at index mid
        }
        if (arr[mid].name < name) {
            left = mid + 1;  // Search right half
        } else {
            right = mid - 1;  // Search left half
        }
    }

    return -1;  // Name not found
}

string EmpPassword[row] = {};
string EmpName[row] = {};

// Class definition for the 'employee' class, derived from 'admin_main_menu'
class employee : public admin_main_menu
{
	private:
		string Emppassword;
		string Empname;
		
	public:
		void set_employee()
		{
			read_Emp_files();
			 do
		 {	
		    system("cls");
			cout << "***********************************************" << endl;
			cout<<"------\t\tEMPLOYEE ACCOUNT\t ------"<<endl;
			cout<<"==============================================="<<endl;
			cout<<endl<<"\t    >> [1] Add Records  <<"<<endl;
			cout<<"\t   >> [2] Update Records <<"<<endl;
			cout<<"\t   >> [3] Delete Records <<"<<endl;
			cout<<"\t   >> [4] Search Records <<"<<endl;
			cout<<"\t>> [5] Display All Records <<"<<endl;
			cout<<"\t>> [6] Return to Admin Menu <<"<<endl;
			cout<<"\t       >> [7] Exit <<"<<endl;
			cout<<"==============================================="<<endl;
			cout<<"Select options: ";
			cin>>options;
			switch(options)
			{
				case 1:
					Emp_Add_Records();
					save_Emp_files();
					system("cls");
					break;
				case 2:
					cin.ignore();
					cout<<"Search by Name >>";
					getline(cin,search);
					Emp_Update_Records();
					save_Emp_files();
					system("cls");
					break;
				case 3:
					cin.ignore();
					cout<<endl<<"Delete by Name >>";
					getline(cin,search);
					Emp_Delete_Records();
					save_Emp_files();
					system("cls");
					break;
			    case 4:
			    	cin.ignore();
					Emp_Search_Records();
					cin.ignore();
					system("cls");
					break;
				case 5:
					system("cls");
					Emp_Display_Records();
					cin.ignore();
					cin.get();
					system("cls");
					break;	
				case 6:
					return;
				case 7:
					exit(0);
				default:
					cout<<endl<<"Invalid code! Please try again...."<<endl;
					cin.ignore();
					cin.get();
                    system("cls");
			}
			
		   }while(options !=7);
		 }
		
void Emp_Add_Records()//function to add new employee record
{
	cin.ignore();
	cout<<endl<<"Employee Name :";
	getline(cin,Empname);
	cout<<"Employee Password :";
	getline(cin,Emppassword);
	
	for(int i=0;i<row;i++)
	{
		if(EmpName[i].empty())
		{
			EmpName[i] = Empname;
			EmpPassword[i] = Emppassword;
			
			cout<<endl<<"Successful Added!"<<endl;
			cin.get();
			break;
		}//If EmpID array is empty, it means that this slot is available for a new employee record
	}
}//end of the Emp_Add_Records

void Emp_Update_Records()//function to update employee new information manually
{
	int count=0;
	for(int i=0;i<row;i++)
	{
		if(EmpName[i] == search)
		{
			count++;
			
	    cout<<endl<<"Employee Password :";
	    getline(cin,Emppassword);
	    
	    EmpPassword[i] = Emppassword;
	    
	    cout<<endl<<"Successfull Updated!"<<endl;
	    cin.get();
	    break;
		}
	}
	if(count == 0)
	{
		cout<<endl<<"Name does'nt exist!"<<endl;
		cin.get();
	}
}//end of Emp_Update_Records

void Emp_Delete_Records()
{
    int count = 0;

    for (int i = 0; i < row; i++)
    {
        if (EmpName[i] == search)
        {
            count++;

            // Shift elements up
            for (int j = i; j < row - 1; j++)
            {
                EmpName[j] = EmpName[j + 1];
                EmpPassword[j] = EmpPassword[j + 1];
            }

            // Clear the last element
            EmpName[row - 1] = "";
            EmpPassword[row - 1] = "";

            cout << endl << "Successfully Deleted!" << endl;
            cin.get();

            // Since we shifted elements, we need to decrement `i` to avoid skipping an element
            i--;
        }
    }

    if (count == 0)
    {
        cout << endl << "ID doesn't exist!" << endl;
        cin.get();
    }
}

void Emp_Search_Records() {
	user records[row];
    int recordCount = 0;
    for (int i = 0; i < row; i++) {
        if (!EmpName[i].empty()) {
            records[recordCount] = {EmpName[i], EmpPassword[i]};
            recordCount++;
        }
    }
    
    cout << "Search by Name >>";
    getline(cin, search);
    system("cls");
    
    cout << "\t        CURRENT EMPLOYEE" << endl;
    cout << "==================================================" << endl;
    cout << "No. |       Name        |       Password    " << endl
             << "----------------------------------------------------\n";
             
    // Added sorting before searching to ensure binary search works correctly
    selectionSort(EmpName, EmpPassword, recordCount);
    for (int i = 0; i < recordCount; ++i) {
        records[i] = {EmpName[i], EmpPassword[i]};
    }

    int index = binarySearch(records, recordCount, search);
    if (index != -1) {
  
	    cout << setw(8) << left << (index + 1) << setw(24) << left << records[index].name << setw(10) << right << records[index].password << endl;
    
	} else {
    	
        cout << "No Record Found!" << endl;
    }
    
    cout << "--------------------------------------------------" << endl;
}

void Emp_Display_Records() {
    string names[row];
    string passwords[row];
    int count = 0;

    // Gather non-empty records
    for (int i = 0; i < row; i++) {
        if (!EmpName[i].empty()) {
            names[count] = EmpName[i];
            passwords[count] = EmpPassword[i];
            count++;
        }
    }

    // Display unsorted data
    cout << "" << endl;
    cout << "\t         Current Unsorted Record" << endl;
    cout << "====================================================" << endl;
    cout << "No. |       Name        |       Password    " << endl << "----------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << setw(8) << left << (i + 1) << setw(24) << left << names[i] << setw(10) << right << passwords[i] << endl;
    }
    if (count == 0) {
        cout << "No Record found!" << endl;
        return;
    }

    // Ask if the admin wants to sort the data
    char sortOption;
    cout << "\nDo you want to sort the records? (y/n): ";
    cin >> sortOption;

    if (sortOption == 'y' || sortOption == 'Y') {
        // Sort the records
        selectionSort(names, passwords, count);

        // Display sorted data
        cout << "" << endl;
        cout << "\t         Current Sorted Record" << endl;
        cout << "====================================================" << endl;
        cout << "No. |       Name        |       Password    " << endl << "----------------------------------------------------\n";
        for (int i = 0; i < count; i++) {
            cout << setw(8) << left << (i + 1) << setw(24) << left << names[i] << setw(10) << right << passwords[i] << endl;
        }
    } else {
        cout << "\nReturning to previous menu..." << endl;
    }
}
  
void read_Emp_files()//function to read the employee information from Employee.txt file
	{
		int i;
		ifstream read_emp;
		read_emp.open("Employee.txt");
		if(read_emp)
		{
		 
		  for (int i = 0; i < row; i++)
        {
            if (!(read_emp >> EmpName[i] >> EmpPassword[i]))
                break;
        }
		}
		else
		{
			cout<<"File does not exist"<<endl;
			exit(0);
		}
		read_emp.close();
	}
	 
void save_Emp_files()//function to write and save the employee information to Employee.txt file
    {
  	    ofstream save_emp;
  	    save_emp.open("Employee.txt");
  	    
  	    if(save_emp)
  	    {
  	    	for(int i=0;i<row;i++)
  	    	{
  	    		if(EmpName[i].empty())
  	    		{
  	    			break;
				}
				else
				{
					save_emp << EmpName[i]<<"  "<< EmpPassword[i]<<endl;
				}
			}
		}
		else
		{
			cout<<"File does not exist!"<<endl;
			exit(0);
		}
		save_emp.close();
    }	
};

string CusName[row] = {};  
string CusPassword[row] = {};
// Class definition for the 'customer' class, derived from 'admin_main_menu'
class customer : public admin_main_menu
{
	private:
		string cusname;
		string cuspassword;
	public:
		void set_customer()
		{
			read_Cus_files();
			do
			{
			system("cls");
		    cout << "***********************************************" << endl;
			cout<<"------\t\tCUSTOMER ACCOUNT\t ------"<<endl;
			cout<<"==============================================="<<endl;
			cout<<endl<<"\t    >> [1] Add Records  <<"<<endl;
			cout<<"\t   >> [2] Update Records <<"<<endl;
			cout<<"\t   >> [3] Delete Records <<"<<endl;
			cout<<"\t   >> [4] Search Records <<"<<endl;
			cout<<"\t>> [5] Display All Records <<"<<endl;
			cout<<"\t>> [6] Return to Admin Menu <<"<<endl;
			cout<<"\t       >> [7] Exit <<"<<endl;
			cout<<"==============================================="<<endl;
			cout<<"Select options: ";
			cin>>options;
			switch(options)
			{
				case 1:
					Cus_Add_Records();
                    save_Cus_files();
					system("cls");
					break;
				case 2:
					cin.ignore();
					cout<<"Search by Name >>";
					getline(cin,search);
					Cus_Update_Records();
                    save_Cus_files();
					system("cls");
					break;
				case 3:
					cin.ignore();
					cout<<endl<<"Delete by Name >>";
					getline(cin,search);
					Cus_Delete_Records();
	                save_Cus_files();
					system("cls");
					break;
			    case 4:
			    	cin.ignore();
					Cus_Search_Records();
					cin.ignore();
					system("cls");
					break;
				case 5:
					system("cls");
					Cus_Display_Records();
					cin.ignore();
					cin.get();
					system("cls");
					break;	
				case 6:
					return;
				case 7:
					exit(0);
				default:
					cout<<endl<<"Invalid code! Please try again...."<<endl;
					cin.ignore();
					cin.get();
                    system("cls");
			}
			
		   }while(options !=7);
	    }
void Cus_Add_Records()//function to add new customer record
{
	cin.ignore();
	cout<<endl<<"Customer Name :";
	getline(cin,cusname);
	cout<<"Customer Password :";
	getline(cin,cuspassword);
	
	for(int i=0;i<row;i++)
	{
		if(CusName[i].empty())
		{
			CusName[i] = cusname;
			CusPassword[i] = cuspassword;
			
			cout<<endl<<"Successful Added!"<<endl;
			cin.get();
			break;
		}//If EmpID array is empty, it means that this slot is available for a new Customer record
	}
}//end of the Cus_Add_Records

void Cus_Update_Records()//function to update the customer new record
{
	int count=0;
	for(int i=0;i<row;i++)
	{
		if(CusName[i] == search)
		{
			count++;
			
	    cout<<endl<<"Customer Password :";
	    getline(cin,cuspassword);
	    
	    CusPassword[i] = cuspassword;
	    
	    cout<<endl<<"Successfull Updated!"<<endl;
	    cin.get();
	    break;
		}
	}
	if(count == 0)
	{
		cout<<endl<<"Name does'nt exist!"<<endl;
		cin.get();
	}
}//end of Cus_Update_Records

void Cus_Delete_Records()
{
    int count = 0;

    for (int i = 0; i < row; i++)
    {
        if (CusName[i] == search)
        {
            count++;

            // Shift elements up
            for (int j = i; j < row - 1; j++)
            {
                CusName[j] = CusName[j + 1];
                CusPassword[j] = CusPassword[j + 1];
            }

            // Clear the last element
            CusName[row - 1] = "";
            CusPassword[row - 1] = "";

            cout << endl << "Successfully Deleted!" << endl;
            cin.get();

            // Since we shifted elements, we need to decrement `i` to avoid skipping an element
            i--;
        }
    }

    if (count == 0)
    {
        cout << endl << "ID doesn't exist!" << endl;
        cin.get();
    }
}

void Cus_Search_Records() {
	user records[row];
    int recordCount = 0;
    for (int i = 0; i < row; i++) {
        if (!CusName[i].empty()) {
            records[recordCount] = {CusName[i], CusPassword[i]};
            recordCount++;
        }
    }
    
    cout << "Search by Name >>";
    getline(cin, search);
    system("cls");
    
    cout << "\t        CURRENT EMPLOYEE" << endl;
    cout << "==================================================" << endl;
    cout << "No. |       Name        |       Password    " << endl
             << "----------------------------------------------------\n";
             
    // Added sorting before searching to ensure binary search works correctly
    selectionSort(CusName, CusPassword, recordCount);
    for (int i = 0; i < recordCount; ++i) {
        records[i] = {CusName[i], CusPassword[i]};
    }

    int index = binarySearch(records, recordCount, search);
    if (index != -1) {
  
	    cout << setw(8) << left << (index + 1) << setw(24) << left << records[index].name << setw(10) << right << records[index].password << endl;
    
	} else {
    	
        cout << "No Record Found!" << endl;
    }
    
    cout << "--------------------------------------------------" << endl;
}

void Cus_Display_Records() {
    string names[row];
    string passwords[row];
    int count = 0;

    // Gather non-empty records
    for (int i = 0; i < row; i++) {
        if (!CusName[i].empty()) {
            names[count] = CusName[i];
            passwords[count] = CusPassword[i];
            count++;
        }
    }

    // Display unsorted data
    cout << "" << endl;
    cout << "\t         Current Unsorted Record" << endl;
    cout << "====================================================" << endl;
    cout << "No. |       Name        |       Password    " << endl << "----------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << setw(8) << left << (i + 1) << setw(24) << left << names[i] << setw(10) << right << passwords[i] << endl;
    }
    if (count == 0) {
        cout << "No Record found!" << endl;
        return;
    }

    // Ask if the admin wants to sort the data
    char sortOption;
    cout << "\nDo you want to sort the records? (y/n): ";
    cin >> sortOption;

    if (sortOption == 'y' || sortOption == 'Y') {
        // Sort the records
        selectionSort(names, passwords, count);

        // Display sorted data
        cout << "" << endl;
        cout << "\t         Current Sorted Record" << endl;
        cout << "====================================================" << endl;
        cout << "No. |       Name        |       Password    " << endl << "----------------------------------------------------\n";
        for (int i = 0; i < count; i++) {
            cout << setw(8) << left << (i + 1) << setw(24) << left << names[i] << setw(10) << right << passwords[i] << endl;
        }
    } else {
        cout << "\nReturning to previous menu..." << endl;
    }
}
  
  void read_Cus_files()//function to read the customer information
	{
		int i;
		ifstream read_Cus;
		read_Cus.open("Customer.txt");
		if(read_Cus)
		{
		 
		  for (int i = 0; i < row; i++)
        {
            if (!(read_Cus >> CusName[i] >> CusPassword[i]))
                break;
        }
		}
		else
		{
			cout<<"File does not exist"<<endl;
			exit(0);
		}
		read_Cus.close();
	}
	 
void save_Cus_files()//function to write the customer information
    {
  	    ofstream save_Cus;
  	    save_Cus.open("Customer.txt");
  	    
  	    if(save_Cus)
  	    {
  	    	for(int i=0;i<row;i++)
  	    	{
  	    		if(CusName[i].empty())
  	    		{
  	    			break;
				}
				else
				{
					save_Cus << CusName[i]<<"  "<< CusPassword[i]<<endl;
				}
			}
		}
		else
		{
			cout<<"File does not exist!"<<endl;
			exit(0);
		}
		save_Cus.close();
    }	
    
};

class admin : private employee//inheritance
{	
private:
	string userID, password, id, pass;
	public:
		employee emp;
		PetFoods pf;
		customer ct;
        bool again = true;
        
		void menu(bool &previous) {
    admin_main_menu mm;
    bool again = true;  // Ensure 'again' is defined
    while (!previous) {  // Continue until previous is true
        system("cls");
        mm.set_main_menu();
        do {
            cout << endl << "Select option >>";
            cin >> options;
            
            if (options < 1 || options > 4)
                cout << "Invalid options! please reenter again\n";
                
        } while (options < 1 || options > 4);
        
        switch (options) {
            case 1:
                again = true;
                emp.set_employee();
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 2:
                again = true;
                ct.set_customer();
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 3:
                again = true;
                pf.petfoods_menu();
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 4:
                previous = true;
                return;  // Break out of the loop and return to the caller
        }
    }
}//end of menu

	    friend void admin_login(admin& a);//friend
	    friend void customer_login();//friend
	    
};//end of class admin

void customer_menu(bool &previous);
void customer_login();
void registration();
void forgot();
void petmenu();  // Declare petmenu function
void display();// Declare display function  
void searchItemName();
PetFoodStore petStore;

//customer menu
void customer_menu(bool &previous) {
	//function to display the login page and options
    int c;
    bool again = true;
    admin a;
    
    do{
    	system("cls");
    cout << "\t\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n\n";
    cout<<"\t\t\t   ============================================================"<<endl;
    cout << "\n\t\t\t    -----------   WELCOME DOLK PET FOOD STORE     -----------           \n\n";
    cout<<"\t\t\t   ============================================================\n\n"<<endl;
    cout << "\t\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n\n";

    
	  cout << "\t\t\t\t\t\t_Login Page_\n\n\n";
    cout << "\t\t\t\t| Press 1 to LOGIN                       |\n";
    cout << "\t\t\t\t| Press 2 to REGISTER                    |\n";
    cout << "\t\t\t\t| Press 3 if you forget your PASSWORD    |\n";
    cout << "\t\t\t\t| Press 4 to EXIT                        |\n";
    do{
    cout << "\n\t\t\t   Please enter your choice: ";
    cin >> c;
    
    if(c < 1 || c > 4)
    cout << "Invalid options! please reenter again\n";
    
     }while(c < 1 || c > 4);
    cout << endl;

    switch (c) {
        case 1:
        	again = true;
            customer_login();
            break;
        case 2:
        	again = true;
            registration();
            break;
        case 3:
        	again = true;
            forgot();
            break;
        case 4:
             previous = true;
             return;
    }
  }while(true);
}

int main() {
    // Existing main function code
    admin a;
    int choice;
    bool previous = true;
    
    do{
    	system("cls");
    cout << "\t\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n\n";
    cout<<"\t\t\t   ============================================================"<<endl;
    cout << "\n\t\t\t	-----------     DOLK PET FOOD STORE     -----------           \n\n";
    cout<<"\t\t\t   ============================================================\n\n"<<endl;
    cout << "\t\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n\n";

    cout << "\t\t\t\t\t\t_Main Menu_\n\n\n";
    cout << "\t\t\t\t |          Press 1 for Customer           |\n";
    cout << "\t\t\t\t |          Press 2 for Admin              |\n";
    cout << "\t\t\t\t |          Press 3 to Exit                |\n";
    
    do{
    cout << "\n\t\t\t   Please enter your choice: ";
    cin >> choice;
    
     if (choice < 1 || choice > 3)
        cout << "Invalid options! please reenter again\n";
        
     }while(choice < 1 || choice > 3);
     
    switch (choice) {
        case 1:
        	previous = false;
            customer_menu(previous); // Proceed to login
            break;
        case 2:
        	previous = false;
        	admin_login(a);
            a.menu(previous);
            break;
        case 3:
        	previous = false;
            cout << "\t\t\t  Thank you!   \n\n";
            break;
        }
  } while (previous);
    return 0;
}

//admin menu
void admin_login(admin& a)
{	//function to let admin login their information
	int count = 0;
    system("cls");
    cout << "\t\t\t Please enter the username and password:" << endl;
    cout << "\t\t\t USERNAME:";
    cin >> a.userID;
    cout << "\t\t\t PASSWORD:";
    cin >> a.password;

    ifstream fEmployee("Employee.txt");

      while (fEmployee >> a.id >> a.pass) {
        if (a.id == a.userID && a.pass == a.password) {
            count = 1;
            cout << endl << "\t\t\t"<< a.userID << "\n \t\t\tYour LOGIN is successful \n \t\t\tThanks for logging in! \n"; 
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }
    }
     fEmployee.close();
     
     if (count == 0) {
        cout << "\n LOGIN ERROR \n Please check your username and password\n";
        cin.ignore();
        cin.get();
        system("cls");
        main();
    }
}

void customer_login() {
    int count = 0; // Initialize count to 0
    string userID, password; // Use string instead of char arrays
    system("cls");
    cout << "\t\t\t Please enter the username and password:" << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userID;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("Customer.txt");
    string storedUserID, storedPassword;

    while (input >> storedUserID >> storedPassword) {
        if (storedUserID == userID && storedPassword == password) {
            count = 1;
            system("cls");
            break;
        }
    }
    input.close();

    if (count == 1) {
        cout << userID << "\n Your LOGIN is successful \n Thanks for logging in! \n";
        display();
    } else {
        cout << "\n LOGIN ERROR \n Please check your username and password\n";
        main(); // Ensure this returns or properly calls the main menu
    }
}


// Product structure to store information about each pet
struct Product {
    string name;
    double price;
    int quantity;  // Added quantity member
};

// Cart structure to store the items added by the user
struct CartItem {
    string name;
    double price;
    int quantity;
};

// Payment structure to store information about the payment
struct Payment {
    int method;
    double amount;
};

    
// Function to display the available products in the pet shop
void displayProducts(const vector<Product>& products) {
    cout << endl << "Available Products:" << endl;
    cout << setw(20) << left << "Product Name" << setw(10) << left << "Price" << setw(10) << left << "Quantity" << endl;
    cout << string(50, '-') << endl;

    stack<Product> productStack;
    for (const auto& product : products) {
        productStack.push(product);
    }

    while (!productStack.empty()) {
        Product product = productStack.top();
        productStack.pop();
        cout << setw(20) << left << product.name << setw(10) << left << product.price
             << setw(10) << left << product.quantity << endl;
    }

    cout << endl;
}

// Function to add a product to the user's shopping cart
void addToCart(vector<CartItem>& cart, vector<Product>& products, const string& productName, int quantity) {
    for (vector<Product>::size_type i = 0; i < products.size(); ++i) {
        if (products[i].name == productName && products[i].quantity >= quantity) {
            CartItem newItem;
            newItem.name = products[i].name;
            newItem.price = products[i].price * quantity;  // Adjust the price based on quantity
            newItem.quantity = quantity;
            cart.push_back(newItem);
			system("cls");
            // Update the available quantity in the products list
            products[i].quantity -= quantity;
			
            cout << "Added " << quantity << " units of " << products[i].name << " to the cart." << endl;
            
            // Display available products again
            displayProducts(products);
            
            
            return;
        } else if (products[i].name == productName) {
            cout << "Insufficient quantity of " << products[i].name << ". Available quantity: " << products[i].quantity << endl;
            return;
        }
    }

    cout << "Product not found. Please enter a valid product name." << endl;
}

// Function to remove a product from the user's shopping cart
void removeFromCart(vector<CartItem>& cart, vector<Product>& products, const string& productName, int quantity) {
    for (vector<CartItem>::size_type i = 0; i < cart.size(); ++i) {
        if (cart[i].name == productName && cart[i].quantity >= quantity) {
            // Update the available quantity in the products list
            for (vector<Product>::size_type j = 0; j < products.size(); ++j) {
                if (products[j].name == productName) {
                    products[j].quantity += quantity;
                    break;
                }
            }

            // Update the quantity in the cart
            cart[i].quantity -= quantity;
            cart[i].price -= (cart[i].price / (cart[i].quantity + quantity)) * quantity;  // Adjust the price accordingly
			system("cls");
            cout << "Removed " << quantity << " units of " << cart[i].name << " from the cart." << endl;

            // If the quantity becomes zero, remove the item from the cart
            if (cart[i].quantity == 0) {
                cart.erase(cart.begin() + i);
            }

            // Display available products again
            displayProducts(products);
            return;
        } else if (cart[i].name == productName) {
            cout << "Insufficient quantity of " << cart[i].name << " in the cart. Available quantity: " << cart[i].quantity << endl;
            return;
        }
    }

    cout << "Product not found in the cart. Please enter a valid product name." << endl;
}

// Function to display the contents of the user's shopping cart
void displayCart(vector<CartItem>& cart) {
    // Sort cart items by name using Selection Sort
    for (size_t i = 0; i < cart.size() - 1; ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < cart.size(); ++j) {
            // Compare names lexicographically
            if (cart[j].name < cart[min_index].name) {
                min_index = j;
            }
        }
        // Swap elements
        if (min_index != i) {
            swap(cart[i], cart[min_index]);
        }
    }

    system("cls");
    cout << "Shopping Cart:" << endl;
    cout << setw(20) << left << "Product Name" << setw(10) << left << "Price" << setw(10) << left << "Quantity" << endl;
    cout << string(50, '-') << endl;

    for (const auto& item : cart) {
        cout << setw(20) << left << item.name << setw(10) << left << item.price 
             << setw(10) << left << item.quantity << endl;
    }

    cout << endl;
}

// Function to calculate the total price of items in the shopping cart
double calculateTotal(const vector<CartItem>& cart) {
    double total = 0.0;
    for (vector<CartItem>::size_type i = 0; i < cart.size(); ++i) {
        total += cart[i].price;
    }
    return total;
}

// Function to perform the payment process
Payment makePayment() {
    Payment payment;

    cout << "\tSelect your Payment Method" << endl;
    cout << "\t===================================" << endl;
    cout << "\t>> [1] Cash  <<" << endl;
    cout << "\t>> [2] Touch n Go eWallet<<" << endl;
    cout << "\t>> [3] DuitNow <<" << endl;
    cout << "\t>> [4] Credit Card <<" << endl;
    cout << "\t>> [5] Exit <<" << endl;
    cout << "Select a Payment Method (1-5): ";
    cin >> payment.method;

    cout << "Enter the payment amount: ";
    cin >> payment.amount;

    if (payment.method == 1) {
        // Show changes for cash payment
        //cout << "Enter the payment amount: ";
        //cin >> payment.amount;
        cout << "Changes: " << payment.amount << endl;
    } else if (payment.method >= 2 && payment.method <= 4) {
        // Display total payment and mention credit for other payment methods
        cout << "Total payment: " << payment.amount << endl; // Assuming payment.amount is the total amount
        cout << "Credit: "  /* calculate credit */ << endl;
    } else if (payment.method == 5) {
        char continueViewStock;
        cout << "Do you want to continue viewing the stock? (Y/N): ";
        cin >> continueViewStock;
        if (continueViewStock == 'N' || continueViewStock == 'n') {
            // Exit or perform any other actions
            cout << "Exiting the system..." << endl;
        } //else {
            // Continue viewing stock or perform any other actions
            //viewStock();
        
    } else {
        cout << "Invalid option. Please select a valid payment method (1-5)." << endl;
    }

    return payment;
}


// Function to save the contents of the shopping cart to a file
void saveToFile(const vector<CartItem>& cart, const Payment& payment) {
    // Open a file named "sales_info.txt" in append mode
    ofstream outFile("sales_info.txt", ios::app);

    // Check if the file is opened successfully
    if (outFile.is_open()) {
        outFile << "Receipt:" << endl;
        outFile << setw(20) << left << "Product Name" << setw(10) << left << "Price" << setw(10) << left << "Quantity" << endl;
        outFile << string(50, '-') << endl;

        for (vector<CartItem>::size_type i = 0; i < cart.size(); ++i) {
            outFile << setw(20) << left << cart[i].name << setw(10) << left << cart[i].price 
                 << setw(10) << left << cart[i].quantity << endl;
        }

        double total = calculateTotal(cart);
        outFile << string(50, '-') << endl;
        outFile << setw(20) << left << "Total" << setw(10) << left << total << endl;
        outFile << endl;
        
        // Write payment details to the file
        outFile << "Payment Details" << endl;
        outFile<<"==================================="<<endl;
        outFile << "Method: " << payment.method << endl;
        outFile << "Payment Amount: " << payment.amount << endl;
        outFile << "Change: " << (payment.amount - total) << fixed << setprecision(2) << endl;
        outFile << endl;

        // Close the file
        outFile.close();

        cout <<endl<< "Receipt saved to sales_info.txt" << endl;
    } else {
        cout <<endl<< "Error opening the file for writing." << endl;
    }
}



// Function to print out the receipt
void printReceipt(const vector<CartItem>& cart) {
	double change=0;
	char date[80];
	char time[80];
	
	system("cls");
    cout << "Receipt:" << endl;
    cout << setw(20) << left << "Product Name" << setw(10) << left << "Price" << setw(10) << left << "Quantity" << endl;
    cout << string(50, '-') << endl;

    for (vector<CartItem>::size_type i = 0; i < cart.size(); ++i) {
        cout << setw(20) << left << cart[i].name << setw(10) << left << cart[i].price 
             << setw(10) << left << cart[i].quantity << endl;
    }

    double total = calculateTotal(cart);
    cout << string(50, '-') << endl;
    cout << setw(20) << left << "Total" << setw(10) << left << total << endl;
    cout << endl;
    
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    
    std::strftime(date, 80, "%Y-%m-%d ", now);
    std::strftime(time, 80, "%H:%M:%S", now);
    
    Payment payment = makePayment();
	
	change = payment.amount-total;
	system("cls");
    cout << "Payment Details" << endl;
    cout << "============================"<<endl;
    std::cout << date << "\t";
    std::cout << time << "\n\n";
    cout << "Method: " << payment.method<<endl;
    cout << "Payment Amount: " << payment.amount<<endl;
    cout << "Change: " << change<<fixed<<setprecision(2)<<endl;
    
    saveToFile(cart,payment);
    
    
}

void FoodDetail(const string& filename) {
    //function to display the add to cart petfood detail
    vector<Product> products;
    if(filename=="Cat.txt" )
{
	
   // Read Cat food details
    string filenameCat = "Cat2.txt";
    ifstream fileCat(filenameCat.c_str());

    if (!fileCat.is_open()) {
        cout << "File " << filenameCat << " does not exist or could not be opened." << endl;
        exit(0);
    }

    PetFood petFoodCat;
    while (fileCat >> petFoodCat.code >> petFoodCat.price >> petFoodCat.quantity) {
        products.push_back({petFoodCat.code, petFoodCat.price, petFoodCat.quantity});
        
    }

    fileCat.close();
}

	else if(filename== "Dog.txt")
{
	// Read Dog food details
    string filenameDog = "Dog2.txt";
    ifstream fileDog(filenameDog.c_str());

    if (!fileDog.is_open()) {
        cout << "File " << filenameDog << " does not exist or could not be opened." << endl;
        exit(0);
    }

    PetFood petFoodDog;
    while (fileDog >> petFoodDog.code >> petFoodDog.price >> petFoodDog.quantity) {
        products.push_back({petFoodDog.code, petFoodDog.price, petFoodDog.quantity});
    }

    fileDog.close();
}

	else if(filename== "Bird.txt")
{
	// Read Dog food details
    string filenameBird = "Bird2.txt";
    ifstream fileBird(filenameBird.c_str());

    if (!fileBird.is_open()) {
        cout << "File " << filenameBird << " does not exist or could not be opened." << endl;
        exit(0);
    }

    PetFood petFoodBird;
    while (fileBird >> petFoodBird.code >> petFoodBird.price >> petFoodBird.quantity) {
        products.push_back({petFoodBird.code, petFoodBird.price, petFoodBird.quantity});
    }

    fileBird.close();
}
  


    // User's shopping cart
    vector<CartItem> cart;

    // Display available products
    displayProducts(products);
    
   

    // Interaction with the user
    while (true) {
        cout << "===============================================" << endl;
        cout<<endl<<"\t>> [1] Add To Cart  <<"<<endl;
        cout<<"\t>> [2] Remove From Cart <<"<<endl;
        cout<<"\t>> [3] View Cart <<"<<endl;
        cout<<"\t>> [4] Print Out Receipt <<"<<endl;
        cout<<"\t>> [5] Exit <<"<<endl;
        
        cout << "Enter a command (1-5): ";
        string command;
        cin >> command;

        if (command == "1") {
            cout << "Enter the product code to add to the cart: ";
            string productName;
            cin.ignore(); // Clear the input buffer
            getline(cin, productName);

            cout << "Enter the quantity: ";
            int quantity;
            cin >> quantity;

            addToCart(cart, products, productName, quantity);
            
        } else if (command == "2") {
            cout << "Enter the product code to remove from the cart: ";
            string productName;
            cin.ignore(); // Clear the input buffer
            getline(cin, productName);

            cout << "Enter the quantity: ";
            int quantity;
            cin >> quantity;

            removeFromCart(cart, products, productName, quantity);
        } else if (command == "3") {
            displayCart(cart);
        } else if (command == "4") {
            printReceipt(cart);
            break; // Exit the loop after printing the receipt
        } else if (command == "5") {
        	system("cls");
        	petStore.PetOptions();
            break; // Exit the program
             
        } 
		else {
            cout << "Invalid command. Please enter a valid command." << endl;
        }
    }
		
    //return 1;
}

// Structure for pet information
struct Pet {
    string code;
    string foodName;
    string petType;
    double price;
    int quantity;
};



class PetStore {
public:
	PetStore()//constructor 
	{
		cout<<endl<<"===================================================="<<endl;
		cout<<"----\t      WELCOME TO PET FOOD STORE  \t----"<<endl;
		cout<<"===================================================="<<endl;
		cout<<"Please choose your pet...."<<endl;
	}
	
    void PetOptions() {
        // Implement the function to display pet options
        // You can customize this based on your requirements
        cout <<endl<< "1. Cat" << endl;
        cout << "2. Dog" << endl;
        cout << "3. Bird" << endl;
        cout << "4. Search Item Name" <<endl;
        cout << "5. Display Sorted Data" << endl;
        cout << "6. Display Unsorted Data" << endl;
    }
};

//function to sort customer petfood by name
void merge(vector<Pet> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Pet> L(n1);
    vector<Pet> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].foodName <= R[j].foodName) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function for vector<Pet>
void mergeSort(vector<Pet> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to compare two pets by food name
bool compareByName(const Pet &a, const Pet &b) {
    return a.foodName < b.foodName;
}

// Function to read pet items from file and store in vector
vector<Pet> readPetsFromFile(const string &filename) {
    vector<Pet> pets;
    ifstream file(filename.c_str());
    if (file.is_open()) {
        Pet pet;
        while (file >> pet.code >> pet.foodName >> pet.petType >> pet.price >> pet.quantity) {
            pets.push_back(pet);
        }
        file.close();
    }
    return pets;
}

// Function to search for an item name in all files
void searchItemName(const string &keyword) {
    vector<Pet> allPets;
    string filenames[] = {"Cat.txt", "Dog.txt", "Bird.txt"};

    // Read all pets from files
    for (int i = 0; i < 3; ++i) {
        vector<Pet> pets = readPetsFromFile(filenames[i]);
        allPets.insert(allPets.end(), pets.begin(), pets.end());
    }

    // Sort the combined vector by food name
    mergeSort(allPets, 0, allPets.size() - 1);

    // Perform linear search for partial matches
    cout << "---------------------------------------------------------------------------------------------------------------------\n";
    cout << setw(6) << left << "Code" << setw(70) << left << "Food Name" << setw(20) << left << "Pet Type" << setw(9) << right << "Price" << setw(13) << right << "Quantity" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------\n";

    bool found = false;
    for (size_t i = 0; i < allPets.size(); ++i) {
        if (allPets[i].foodName.find(keyword) != string::npos) {
            found = true;
            Pet pet = allPets[i];
            cout << setw(6) << left << pet.code << setw(70) << left << pet.foodName << setw(20) << left << pet.petType << setw(10) << right << pet.price << setw(10) << right << pet.quantity << endl;
        }
    }

    if (!found) {
        cout << "No matching items found." << endl;
    }
}

// Function to display products
void displayProducts(const vector<Pet>& products) {
    cout << "---------------------------------------------------------------------------------------------------------------------\n";
    cout << setw(6) << left << "Code" << setw(70) << left << "Food Name" << setw(20) << left << "Pet Type" << setw(9) << right << "Price" << setw(13) << right << "Quantity" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------\n";
    for (const auto& pet : products) {
        cout << setw(6) << left << pet.code << setw(70) << left << pet.foodName << setw(20) << left << pet.petType << setw(10) << right << pet.price << setw(10) << right << pet.quantity << endl;
    }
}
void display() {
    int petChoice;
    PetStore petStore;

    do {
        petStore.PetOptions();

        cout << "Select an option (1-6, 0 to exit): ";
        cin >> petChoice;
        system("cls");

        if (petChoice >= 1 && petChoice <= 3) {
            string filename;

            switch (petChoice) {
                case 1:
                    filename = "Cat.txt";
                    break;
                case 2:
                    filename = "Dog.txt";
                    break;
                case 3:
                    filename = "Bird.txt";
                    break;
            }

                   ifstream file(filename.c_str());

            if (!file.is_open()) {
                cout << "File does not exist or could not be opened." << endl;
                exit(0);
            }

            // Display pets from stack
            cout << "---------------------------------------------------------------------------------------------------------------------\n";
            cout << setw(6) << left << "Code" << setw(70) << left << "Food Name" << setw(20) << left << "Pet Type" << setw(9) << right << "Price" << setw(13) << right << "Quantity" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------------\n";
 			Pet pet;
            while (file >> pet.code >> pet.foodName >> pet.petType >> pet.price >> pet.quantity) {
                cout << setw(6) << left << pet.code << setw(70) << left << pet.foodName << setw(20) << left << pet.petType << setw(10) << right << pet.price << setw(10) << right << pet.quantity << endl;
            }
			 file.close();
            FoodDetail(filename); // Ensure this call is made if necessary

        } else if (petChoice == 4) {
            string keyword;
            cout << "Enter the item name to search: ";
            cin >> keyword;

            // Perform search
            searchItemName(keyword);
        } else if (petChoice == 5 || petChoice == 6) {
            string filename;

            int petTypeChoice;
            cout << "Select pet type for display (1. Cat, 2. Dog, 3. Bird): ";
            cin >> petTypeChoice;

            switch (petTypeChoice) {
                case 1:
                    filename = "Cat.txt";
                    break;
                case 2:
                    filename = "Dog.txt";
                    break;
                case 3:
                    filename = "Bird.txt";
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    continue;
            }

            vector<Pet> pets = readPetsFromFile(filename);
            if (petChoice == 5) {
                mergeSort(pets, 0, pets.size() - 1);
            }

            displayProducts(pets);
        } else if (petChoice != 0) {
            cout << "Invalid choice. Please try again." << endl;
        }

        // Pause before clearing the screen and re-displaying the options
        cout << "\nPress any key to return to the main menu..." << endl;
        cin.ignore(); // Ignore the newline character left in the buffer
        cin.get();    // Wait for user input

    } while (petChoice != 0);
}





void registration() {
    // Existing registration function code
    string ruserID, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t  Enter the username :";
    cin >> ruserID;
    fflush(stdin);
    cout << "\t\t\t    Enter the password:";
    cin >> rpassword;

    ofstream f1("Customer.txt", ios::app);
    f1 << ruserID << "  " << rpassword << endl;
    system("cls");
    cout << "\n\t\t  Registration is successful! \n";
    main();
}

void forgot() {
    // Existing forgot function code
    int option;
    cin.ignore();
    cin.get();
    system("cls");
    cout << "\t\t\t You forget the password? No worries \n";
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "\t\t\t  Enter your choice:";
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string suserID, sID, spass;
			cout << "\n\t\t\tEnter the username which you remembered:";
            cin >> suserID;

            ifstream f2("Customer.txt");
            while (f2 >> sID >> spass) {
                if (sID == suserID) {
                    count = 1;
                }
            }
            f2.close();
            
            if (count == 1) {
                cout << "\n\n Your account is found! \n";
                cout << "\n\n Your password is:" << spass<<endl;
                main();
            } else {
                cout << "\n\t Sorry! your account is not found! \n";
                main();
            }
            break;
        }

        case 2: {
            main();
            break;
        }
         default: {
            cout << "\t\t\t  Wrong choice ! Please try again" << endl;
			forgot();
}
}
}
