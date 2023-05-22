
#include<iostream>

#include<bits/stdc++.h>

using namespace std;


/*

algorithm:insert 


1.push_back(last index)

2. up_heapify()

    -compare child & parent

      -swap()



 algorithm:delete

  

 1.Swap:last value and root.

      -pop_back()


 2.down_heapify()

   *compare between both child
     -select greater one.

    

   *compare selected child and parent.
     -swap(parent,child)


*/



class max_heap {


public:


        vector<int>A;


        max_heap()

         { }


        void up_heapify(int i)

         {

                while(i>0 && A[i]>A[i/2])

                    {

                        swap(A[i],A[i/2]);

                        i=i/2;


                    
        }

            
    }


        void insert(int x)

         {   A.push_back(x);


                up_heapify(A.size()-1);


            
    }




        void down_heapify(int i )

         {

                int child=2*i; //left child




                while(child<A.size()-1)

                    {

                        // compare left and right child

                        if(child<A.size() && A[child]<A[child+1])

                                child=child+1;


                        //compare child and parent

                        if(A[child]>A[i])

                            {
                  swap(A[child],A[i]);
                          
                      i=child;

                                child=2*i;

                            
            }

                        else //swap na hole

                                break;



                    
        }





            
    }



        void Delete(int i)

         {


                if(i>=A.size()-1)

                        return;

//swap last and root element.

                swap(A[0],A[A.size()-1]);

                A.pop_back();


                down_heapify(i);

            
    }


        void print()

         {

                for(int i=0; i<=A.size()-1; i++)

                        cout<<A[i]<<" ";



            
    }




        int getMax() {

                if(A.empty()) {

                        cout<<"Heap is empty!\n";

                        return -1;

                    
        }

                return A[0];

            
    }

    int ExtractMax() {
        if(A.empty()) {
            cout<<"Heap is empty!\n";
            return -1;
        }
        int x =A[0];
        Delete(0);
        return x;
    }

    void build_from_array(vector<int>&a) {
        A = a;
        int n = A.size();

        for(int i=n/2-1; i>=0; i--) {
            down_heapify(i);
        }
    }



};



//O(nlogn)
vector<int> heap_sort(vector<int>a) {
    max_heap heap;
    heap.build_from_array(a);

    vector<int>ans;
    for(int i=0; i<a.size(); i++) {
        ans.push_back(heap.ExtractMax());
    }
    reverse(ans.begin(),ans.end());
    return ans;
}










int main()

{

        max_heap heap;


        heap.insert(20);

        heap.insert(25);

        heap.insert(40);

        heap.insert(5);

        heap.insert(30);

        heap.insert(60);

        heap.insert(75);

       heap.insert(35);


        cout<<"Maximum value:"<<heap.getMax()<<endl;

        heap.print();

        cout<<endl;

        heap.Delete(0);

        heap.print();

        cout<<"\nMaximum value:"<<heap.getMax()<<endl;



        cout<<endl;

        heap.print();
    cout<<endl;
    vector<int>a = {1,2,3,4,10,9,8,7};
    heap.build_from_array(a);
    cout<<" Heapify:\n";
        heap.print();

    cout<<endl;

    cout<<"Heap Short:\n";
    vector<int>sorted_a = heap_sort(a);
    for(int i=0; i<sorted_a.size(); i++) {
        cout<<sorted_a[i]<<" ";
    }
    cout<<"\n";


        return 0;

}










