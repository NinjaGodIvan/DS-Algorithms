public class Playground {
	
	//Sorts the array using selection sort
	public static void selectionSort(int arr[]) {
		
		//Outer loop assigns the pivot
		for(int i = 0; i < arr.length-1; i++) {
			
			//Smallest value from the partial unsorted array
			int smallestValue = Integer.MAX_VALUE;
			//Index containing the smallest value
			int smallestIndex = 0;
			
			//Loops through all values from the partial unsorted array 
			for(int j = i+1; j < arr.length; j++) {
				if(arr[j] < smallestValue) {
					smallestValue = arr[j];
					smallestIndex = j;
				}
			}
			
			//Swaps elements
			if(smallestValue < arr[i]) {
				int temp = arr[smallestIndex];
				arr[smallestIndex] = arr[i];
				arr[i] = temp;
			}
		}
		
	}
	
	//Sorts the array using bubble sort (Worst Method)
	public static void bubbleSort(int arr[]) {
		
		//Repeats until the array is sorted
		while(true) {
			
			//Checks if the elements are swapped at least once in the iteration
			boolean swapped = false;
			
			//Iterates through the array
			for(int i = 0; i < arr.length-1; i++) {
				if(arr[i] > arr[i+1]) {
					int temp = arr[i+1];
					arr[i+1] = arr[i];
					arr[i] = temp;
					swapped = true;
				}
			}
			
			//Stop when the array is sorted
			if(!swapped)
				break;
		}
	}

	public static void main(String[] args) {
		
		int [] arr = {22,11,100,5,23,56,1030, -100, -6969};
		
		//Before sorting the array
		System.out.println("Before sort:");
		for(int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		
		//selectionSort(arr);
		bubbleSort(arr);
		
		//After sorting the array
		System.out.println("After sort:");
		for(int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}

}
