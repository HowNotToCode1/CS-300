/* Alfonso Arreola
 * m233n993
 * 9/16
 * Program that keeps track of inventory
 * */
 
 #include <iostream>
 #include <fstream>
 #include <string>
 using namespace std;
 
 class Part
{
 public:
		int    partNum;
		string description;
		int    quantity;
		float  unitPrice;
};
// function declarations 
void printAllParts(Part [], int);
void addPart(Part[], int&);
void modPart(Part[],int&); 
void totalPrice(Part[], int&);

int main()
{
	// data structure: array of size 100
	
	Part stuff[100];           // array to hold objects
	int count = 0;             // count to tell items apart
	
	
	
	
	// read from file and update stuff
		
	int i = 0; // i is index
	std::fstream file("inventory.txt", std::ios::in);
	
	if(file)
		{
			
			int partNum = 0;
			std::string description = "";
			int quantity = 0;
			float unitPrice = 0;
			
			// use a loop to keep reading file.
			// if reading file fails, the loop will end
			while(file >> partNum)
			{
				
				file.ignore();
				std::getline(file, description);
				file >> quantity;
				file >> unitPrice;
					
				// copy info from local variable to array elements
				stuff[i].partNum 		= partNum;
				stuff[i].description 	= description;
				stuff[i].quantity 		= quantity;
				stuff[i].unitPrice 		= unitPrice;
				
				i++;
				count++;
			}
		}
		else
		 {
			std::cout<<"Error when reading from file \"inventory.txt\""<<std::endl;
		 }
		
		file.close();
	   
	
		
	
		// Menu
	int choice = 0; 
	cout << "User make a choice: "<<endl;
	cout << "--------------------"<<endl;
	cout << "1. Print part"       <<endl;
	cout << "2. Create a part"    <<endl;
	cout << "3. Modify a part"    <<endl;
	cout << "4. Print total"      <<endl;
	cout << "5. Exit"             <<endl;
	cout <<"---------------------"<<endl;
	cin  >> choice;
	while(cin.good() && choice != 5)
	{
		// switch that will follow the users input until 5 is pressed
		switch (choice)
		{ 
			case 1:
					printAllParts(stuff, count);
					break;
            case 2:
					cin.ignore();
					addPart(stuff, count);
					break;
			case 3:
					
					modPart(stuff, count);
					break;
			case 4:
					totalPrice(stuff, count);
					break;
			default:
					cout <<"Invalid choice.(1.Print,2.Create,3.Modify,4.Total,5.Exit)"<<endl;
		}
		cout << "Make a choice: ";
		cin  >> choice;
	}
	
		
	std::fstream file1("inventory.txt", std::ios::out);

if(file1)
	{	
		
		// loop to write new items into the array
		for (i= 0; i < count; i++)
		{
		
			file1 << stuff[i].partNum     <<std::endl;
			file1 << stuff[i].description <<std::endl;
			file1 << stuff[i].quantity    <<std::endl; 
			file1 << stuff[i].unitPrice   <<std::endl;
			
			std::cout<<"Wrote into file successfully."<< endl;
		}
	}
	else
	{
		std::cout<<"Error."<<std::endl;
	}
	
	// close file when done.
	file1.close();
		
return 0;
}

// Function that prints all items in the array
void printAllParts(Part stuff[], int count)
{
	if (count == 0)
	{
		cout << "Empty Inventory"<< endl;  // If nothing is in the array prints out empty inventory 
		return;
	}
	
	
	for (int i = 0; i < count; i++)
	{
		cout << "Part Number: " << stuff[i].partNum      <<endl;
		cout << "Description: " << stuff[i].description  <<endl;
		cout << "Quantity: "    << stuff[i].quantity     <<endl;
		cout << "Unit Price: $"  << stuff[i].unitPrice <<" each."   <<endl;
	}
} 


// Function that adds new parts to inventory
void addPart(Part stuff[], int &count)
{
	cout << "New part description: ";
	string desc;
	getline(cin, desc);
	
	cout << "New part quantity: ";
	int quantity = 0;
	cin >> quantity;
	
	cout << "New part price:$ ";
	float price = 0;
	cin >> price;
	
	// Updates new inputed values to array
	stuff[count].partNum     = count +1;
	stuff[count].description = desc;
	stuff[count].quantity    = quantity;
	stuff[count].unitPrice   = price;
	
	count++;
}
// Function that modifies current parts in array
void modPart(Part stuff[],int &count )
{
	cout << "Enter part to modify: ";
	int value = 0;
    cin  >> value;
    cout << stuff[value].description << endl;
    cout << stuff[value].quantity    << endl;
    cout << "$"<< stuff[value].unitPrice   << endl; 
    

	cout << "Enter item: ";
	string item;
	cin  >> item;


	cout << "Enter quantity: ";
	int quantity = 0;
	cin  >> quantity;
	
	cout << "Enter cost: $";
	float price = 0;
	cin  >> price;
	
	// Updates new inputed values to array
	stuff[value].description = item;
	stuff[value].quantity    = quantity;
	stuff[value].unitPrice   = price;
}
void totalPrice(Part stuff[], int &count)
{
	float total_price;
	for (int i= 0; i < count; i++)
		{
			total_price	= total_price + (stuff[i].quantity * stuff[i].unitPrice);
		}
		
			cout << "Print total: $" << total_price <<endl;

}
