/*This is min-heap
  Heap is indexed from 0
  Left Child  = parent * 2 + 1
  Right Child = parent * 2 + 2
  Parent = (int) (Child - 1)/2
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>

class Heap
{
private:
	std::vector<int> heap_array;
	int parent(int child);
	int leftChild(int parent);
	int rightChild(int parent);
	void heapifyup(int index);
	void heapifydown(int index);
	

public:
	Heap(){}
	void insert(int element);
	void removeMin();
	void removeMax();
	void printHeap();
	int getMin();
};

int Heap::parent(int child)
{
	//element at index 0 doesn't have a parent
	if (child == 0)
		return -1;
	else
		return (int) (child - 1)/2;
}

int Heap::leftChild(int parent)
{
	/*the index of left (and right) child should always be less than
	 the size of the array */
	int left = parent * 2 + 1;
	if(left < heap_array.size())
		return left;
	else
		return -1;
}

int Heap::rightChild(int parent)
{
	int right = parent * 2 + 2;
	if( right < heap_array.size())
		return right;
	else
		return -1;
}


void Heap::insert(int element)
{
	//push element at the end of the heap
	//and then heapify up from the last element
	heap_array.push_back(element);
	heapifyup(heap_array.size() - 1);
}

void Heap::heapifyup(int index)
{
	/*If the heap is not empty and if the element at 'index'
	  has a parent:
	  	If parent of element at index is bigger than the element itself, swap
	*/
	if(index >=0 && parent(index) >=0 && heap_array[parent(index)] > heap_array[index])
	{
		int temp = heap_array[index];
		heap_array[index] = heap_array[parent(index)];
		heap_array[parent(index)] = temp; 
		heapifyup(parent(index));
	}
}

void Heap::heapifydown(int index)
{
	//swap parent with the smaller of it's two children
	//check if the children exist first
	int smaller_child = leftChild(index);
	int bigger_child = rightChild(index);
	if(smaller_child >=0 && bigger_child >=0 && heap_array[smaller_child] > heap_array[bigger_child])
	{
		smaller_child = bigger_child;
	}

	if(smaller_child > 0 && heap_array[index] > heap_array[smaller_child])
	{
		int temp = heap_array[index];
		heap_array[index] = heap_array[smaller_child];
		heap_array[smaller_child] = temp;
		heapifydown(smaller_child);
	}
}

void Heap::removeMin()
{
	if(heap_array.size() == 0)
	{
		std::cout<<"Heap is Empty"<<std::endl;
		return;
	}
	//Swap the minimum element with the last element
	//delete the last element and heapifydown from 0
	heap_array[0] = heap_array[heap_array.size() - 1];
	heap_array.pop_back();
	heapifydown(0);
}

void Heap::removeMax()
{
	if (heap_array.size() == 0)
	{
		std::cout<<"Heap is empty"<<std::endl;
		return;
	}
	else if(heap_array.size() == 1)
	{
		heap_array.pop_back();
	}
	else
	{
		int max_elem = heap_array.size() - 1;
		int max_elem1 = heap_array.size() - 2;

		if (heap_array[max_elem] > heap_array[max_elem1])
		{
			heap_array.pop_back();
		}
		else
		{
			int temp = heap_array[max_elem];
			heap_array[max_elem] = heap_array[max_elem1];
			heap_array[max_elem1] = temp;
			heap_array.pop_back();
		}

	}
}

void Heap::printHeap()
{
	for(int i=0; i<heap_array.size(); i++)
	{
		std::cout<<heap_array[i]<<" ";
	}
}

int Heap::getMin()
{
	if(heap_array.size() >0 )
	{
		return heap_array[0];
	}
	return -1;
}

int main()
{
	Heap heap_obj;

	//Insert elements in heap
	heap_obj.insert(8);
	heap_obj.insert(24);
	heap_obj.insert(6);
	heap_obj.insert(10);
	heap_obj.insert(16);
	heap_obj.insert(18);
	heap_obj.insert(28);

	//Print Heap Elements
	std::cout<<"\nHeap: "<<std::endl;
	heap_obj.printHeap();

	//Print the minimum Element in Heap
	int min_elem = heap_obj.getMin();
	std::cout<<"\n\nMinimum Element in the heap: ";
	min_elem == -1 ? std::cout<<"Heap is Empty "<<std::endl : std::cout<<min_elem<<std::endl;

	//Delete Minimum Element
	heap_obj.removeMin();
	std::cout<<"\nHeap - After deleting minimum Element"<<std::endl;
	heap_obj.printHeap();

	//Delete Maximum Element
	heap_obj.removeMax();
	std::cout<<"\n\nHeap - After deleting maximum Element"<<std::endl;
	heap_obj.printHeap();



	std::cout<<std::endl<<std::endl;
}