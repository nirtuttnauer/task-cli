#!/bin/bash

# Adding multiple tasks
./todo add "Task 1: Buy groceries"
./todo add "Task 2: Walk the dog"
./todo add "Task 3: Complete the report"
./todo add "Task 4: Pay bills"
./todo add "Task 5: Read a book"
./todo add "Task 6: Prepare dinner"
./todo add "Task 7: Call the bank"
./todo add "Task 8: Organize files"
./todo add "Task 9: Plan the weekend"
./todo add "Task 10: Clean the house"
./todo add "Task 11: Attend the meeting"
./todo add "Task 12: Visit the doctor"
./todo add "Task 13: Fix the bike"
./todo add "Task 14: Water the plants"
./todo add "Task 15: Go for a run"
./todo add "Task 16: Finish coding project"
./todo add "Task 17: Respond to emails"
./todo add "Task 18: Plan the presentation"
./todo add "Task 19: Prepare for the interview"
./todo add "Task 20: Submit the application"

# Listing all tasks
./todo list

# Editing tasks
./todo edit 2 "Task 2: Walk the dog in the evening"
./todo edit 10 "Task 10: Deep clean the house"
./todo edit 14 "Task 14: Water the garden plants"
./todo edit 18 "Task 18: Plan and rehearse the presentation"

# Deleting tasks
./todo delete 1
./todo delete 3
./todo delete 5
./todo delete 7
./todo delete 9
./todo delete 11
./todo delete 13
./todo delete 15
./todo delete 19

# Listing remaining tasks
./todo list

# Marking tasks as in-progress
./todo status 2 <<< "2"
./todo status 4 <<< "2"
./todo status 6 <<< "2"
./todo status 8 <<< "2"
./todo status 10 <<< "2"
./todo status 12 <<< "2"
./todo status 16 <<< "2"

# Marking tasks as done
./todo status 2 <<< "3"
./todo status 6 <<< "3"
./todo status 8 <<< "3"
./todo status 12 <<< "3"
./todo status 16 <<< "3"

# Listing tasks by status
./todo list done
./todo list in-progress
./todo list todo

# Adding new tasks to test appending
./todo add "Task 21: Schedule a dentist appointment"
./todo add "Task 22: Buy a gift for the birthday party"
./todo add "Task 23: Write a poem for the competition"
./todo add "Task 24: Arrange the bookshelf"
./todo add "Task 25: Meditate for 20 minutes"
./todo add "Task 26: Practice yoga"
./todo add "Task 27: Update LinkedIn profile"
./todo add "Task 28: Bake a cake"
./todo add "Task 29: Organize a meeting"
./todo add "Task 30: Brainstorm for the new project"

# Listing all tasks again
./todo list

# Testing consecutive deletes
./todo delete 4
./todo delete 10
./todo delete 20
./todo delete 25
./todo delete 30

# Verifying the deleted tasks
./todo list

# Clear specific categories
./todo list done
./todo list in-progress
./todo list todo

# Marking additional tasks as done
./todo status 24 <<< "3"
./todo status 26 <<< "3"
./todo status 28 <<< "3"

# Verifying updates
./todo list done
./todo list todo

# Clearing all tasks
./todo clear <<< "y"

# Final verification
./todo list