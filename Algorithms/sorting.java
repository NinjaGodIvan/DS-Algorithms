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

	public static void main(String[] args) {
		
		int [] arr = {22,11,100,5,23,56,1030, -100, -6969};
		
		//Before sorting the array
		System.out.println("Before sort:");
		for(int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		
		selectionSort(arr);
		
		//After sorting the array
		System.out.println("After sort:");
		for(int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}

}
