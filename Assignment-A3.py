# Assignment-A3

"""
THIS CODE HAS BEEN TESTED AND IS FULLY OPERATIONAL.

Problem Statement: Implement Greedy search algorithm for any of the following application:
  I. Selection Sort
  IV. Job Scheduling Problem

Code from ArtificialIntelligence (SPPU - Third Year - Computer Engineering - Content) repository on KSKA Git: https://git.kska.io/sppu-te-comp-content/ArtificialIntelligence
"""

# BEGINNING OF CODE
# BEGINNING OF SELECTION SORT
numbers = [] # Empty list to store numbers

# Function to take input for numbers
def input_numbers():
        total = int(input("\nHow many numbers you wish to enter?\nTotal numbers:\t"))
        for i in range(total):
                val = float(input(f"Enter number {i+1}:\t"))
                numbers.append(val)
        print("\nNumbers you've entered are:\t", numbers)

# Function for selection sort
def selection_sort():
    for i in range(len(numbers)):
        min_index = i
        for j in range(i+1, len(numbers)):
            if numbers[j] < numbers[min_index]:
                min_index = j
        numbers[i], numbers[min_index] = numbers[min_index], numbers[i] # Swapping
    print("Numbers sorted in ascending order using selection sort:\t", numbers)
# END OF SELECTION SORT

# BEGINNING OF JOB SCHEDULING
def job_scheduling():
    jobs = []
    total = int(input("Total jobs to add:\t"))

    # Take input for jobs
    print("\n", "-"*10, "JOBS", "-"*10, "\n")
    for i in range(total):
        print(f"JOB {i+1} ->")
        job_id = int(input(f"ID for job {i+1}:\t\t"))
        deadline = int(input(f"Deadline for job {i+1}:\t"))
        profit = int(input(f"Profit for job {i+1}:\t"))
        jobs.append((job_id, deadline, profit)) # Index 0 for job_id; Index 1 for deadline; Index 2 for profit
    print(f"\nAdded {total} jobs.")
    print("-"*27, "\n")

    # Initialize
    jobs.sort(key=lambda x: x[2], reverse=True) # Sort jobs by profit; Using index 2 to access profit
    max_deadline = max(job[1] for job in jobs) # Highest deadline; Using index 1 to access deadline
    slots = [0] * (max_deadline + 1)
    total_profit = 0

    # Scheduling jobs using greedy strategy
    for job in jobs:
        for i in range(job[1], 0, -1):
            if slots[i] == 0:
                slots[i] = job[0]
                total_profit += job[2]
                break

    # Print scheduled jobs
    print("Scheduled Jobs:", end=" ")
    for i in range(1, len(slots)):
        if slots[i] != 0:
            print(slots[i], end=" ")

    print(f"\nTotal Profit: {total_profit}")
# END OF JOB SCHEDULING


# Main function for menu
def main():
  while True:
    print("\n\n", "-"*10, "MAIN MENU", "-"*10)
    print("1. Selection Sort")
    print("2. Job Scheduling")
    print("3. Exit")
    choice = int(input("Choose an option (1-3):\t"))
    print("-"*32)

    if (choice == 1):
      input_numbers()
      selection_sort()
    elif (choice == 2):
      job_scheduling()
    elif (choice == 3):
      print("\n## END OF CODE\n")
      break
    else:
      print("\nPlease choose a valid option (1-3)")

main()
# END OF CODE
