/*
JOB SCHEDULING WITH DEADLINE : (Profit Maximization problem)
Objective : To select a set of jobs which gives yeilds to a maximum total profit.

Assuming you are given a total of 'n' jobs to be picked from, each job having a 'profit' and 'deadline' attached to it.
for example : Jobs[n]; where Jobs[i] = {
                                          profit : x;
                                          deadline : y;
                                        }
Constraint : The maximum number of jobs that you can complete is the maximum
             deadline that any job has out of all given jobs, such that max(y) <= n;

            Assume completion of each job takes unit time.

eg : n = 5;
Job     profit    deadline      max jobs that can be completed : 3.
1.      20        2             JOB SLOTS(based on deadline) : 1   2   3
2.      15        2
3.      10        1             deadline : Maximimum time that can be taken to
4.      5         3                        complete that job, can be done earlier.
5.      1         3             eg : A job with a deadline : 3 unit of time can be completed on either 1 or 2 unit of times but,
                                     A job with a deadline : 1, will not wait for more than 1 unit of time.

------------------------------------------------ ALGORITHM -------------------------------------------------------------

1. Sort the jobs in the order such that the jobs with the most profit are picked first.
2. Define your time slot, with its lower limit being 1 to the upper limit being max(deadline) and initialize them as empty.
3. Pick the job, and see if the time slot for the completion of that job(deadline) is unoccupied.
    - If yes, place the job in that time slot.
    - If no, then keep moving down the time slot till you reach an empty slot that can be occupied by that job.
   Once the job is placed (or discarded : no vaccant slot) move on to the next job with lesser profit.
4. Repeat step 4 till you run out of slots to fill.

OPTIMIZATION : keep a track of the slots that are left, as soon as slots left = 0, end program and print the total profit.

-------------------------------------------------- ANALYSIS ---------------------------------------------------------------

Sorting the list based on the profits : O(nlogn)
Running operations till the slots run out : O(k^2) , where k = max(deadline). such that k <= n.
Time taken :
    - Worst Case :  O(nlogn + n^2)  = O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
//----------------------------- SORT ARRAY OF PAIRS IN DSC. ORDER based on profit --------------------------------------------
bool descSort(pair<int, int> &a, pair<int, int> &b)
{
    return (a.first > b.first);
}
//----------------------------------------------------------------------------------------------------------------------------

int main()
{
    vector<pair<int,int>> jobs; // vector to store jobs , such that job -> first : profit
    cout << "Enter the number of jobs scheduled : ";//              job -> second : deadline
    int n;
    cin >> n;
    int max_slot = 0, total = 0;
    for(int i=1; i<=n; i++)
    {
        int profit, deadline;
        cout << "Enter the profit obtained by job " << i <<" followed by the deadline unit of time: ";
        cin >> profit >> deadline;
        if(deadline > max_slot) max_slot = deadline; // finding the upper limit of the time-slot.
        jobs.push_back(make_pair(profit, deadline));
    }
    sort(jobs.begin(), jobs.end(), descSort); // Arrange jobs in desc. order based on their profits.
    int slot[max_slot + 1] = {0}; // Creating a time slot array and initialize it as 0. (1-based)
    int slot_left = max_slot; // Couter to track slots left
    for(auto job = jobs.begin(); job != jobs.end() && slot_left != 0 ; ++job) // iterate jobs till there are slots left to fill.
    {
        if(slot[job -> second] == 0) // If the 'most profit' job at the time has a free slot.
        {
            slot[job -> second] = job->first; // assign the slot to the job.
            total += job -> first; // add it to the total profit.
            slot_left--; // decrement slot counter.
        }
        else // If the 'most profit' does not have a free slot at its max deadline, then check if you can do it earlier.
        {
            for(int j = job -> second; j>=1; --j) // iterate down the time slot (based on the deadline)
            {
                if(slot[j] == 0) // if you get a free slot
                {
                    slot[j] = job -> first; // assign the job
                    total += job -> first; // add it to the total profit
                    slot_left--; // and decrement the slot counter
                    break; // move on to the next job.
                }
            }
        }
    }
    cout << "The scheduled jobs with profit :\n";
    for(int i=1; i<=max_slot; i++) // Display all the jobs placed in their respective slots
    {
        cout << i << " : " << slot[i] << "\n";
    }
    cout << "Total profit from the jobs : " << total; // Display summation of their profits.
    return 0;
}
