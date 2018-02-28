# Taffy Shop Simulation

---
### Introduction

This program is a simulation of a taffy shop done for the St. Mary's University CS Seminar class of Fall 2017

### Background

Tiffany's Salt Water Taffy Shop is a small store in Myrtle Beach, South Carolina, that sells bags of taffy by the pound to customers walking along the boardwalk.
The shop has two (2) serving lines that have different service rates (based on the person taking the orders and running the cash register).
Customers will arrive for service randomly, on a uniform distribution, and will select the line based on its length (selecting the shortest one) and each lien is serviced on a First-Come-First-Served basis.
Each customer can decide to order one of three sizes of bags of taffy, 1/2 lb, 1 lb, or 2lb. Half-pound bags cost $4.29, one-pound bags cost $7.79, and two-pound bags cost #13.99.
Service time for a customer depends on their order size and the line that the customer is in. Service time for line A is 1 minute for a half-pound bag, 2 minutes for a one-pound bag, and 5 minutes for a two-pound bag.

### Problem Description:

To help out Tiffany's Taffy Shop, you are to develop a computer program that helps them study the shop's activity over a hypothetical day. The shop is open for 10 hours per day, 7 days a week.
To simulate a day, you will build a model that runs for 600 minutes (10 hours time 60 minutes per hour). This means that one time step in your simulation is equal to one minute.

You will need to write a program that generates the two queues of customer requests for taffy for one day, and service them according to their order request (1/2 lb, 1 lb, or 2 lb bag).
A customer can only order one item, of one of these three sizes. You must maintain a count of the number of each size that is ordered so that a total count and dollar amount can be calculated at the end of the day. 
You will also need to calculate the average time a customer spends getting taffy, based on their order type (this includes both the time spent in line and the time getting serviced), and a variety of other statistics (as specified below). 
In addition, you must keep track of how many customers were serviced from each line.

Each customer has the following attributes:
1. Their customer ID # - given by the system as the order in which they arrive in the service queues
2. The order size (1/2 lb, 1 lb, or 2 lb bag)
3. Their arrival time in the queue
4. Which queue they waited in
5. What time they started to be served
6. Their departure time from the system (having been served)

You will build the two service request queues with randomly-generated customers, using a random number generator to generate each customer's desired order size, and set it up so that a customer arrives at a uniformly distributed rate each time step with a variable probability entered by the user.
Then, based on the current line sizes, enter the customer into the shortest of the two queues (tie goes to line A).
Skew the order size choice so that about 50% of the orders will be for a one-pound bag, 20% will be for a half-pound bag, and 30% will be for a two-pound bag.
Then, service each customer by taking them off of the service request queue when the server becomes available for the queue they are in and "serving" them their bag of taffy. 
When time is up at the end of the day, do not allow any more customers to join the lines (e.g. do not generate any new customers), but continue to serve those that were in line at closing time until everyone is served.

Upon simulation completion, print out the following statistics:
1. Total number of customers served from each line and the combined total number of customers (e.g. the sum of the two lines)
2. Total servcie time for each line and the combined total sum of service time (e.g. the sum of the two lines)
3. Average customer wait time for each line, and average wait time overall
4. Average customer service tiem for each line, and average service time overall
5. Total number each of 1/2 lb, 1 lb, or 2 lb bags ordered, and total number of bags ordered overall
6. Total amount of money made from each line, and total amount of money made overall
7. Maximum queue size of each line and average queue size of each line
8. How long the stand had to remain open past cloisng time to service the remaining customers
9. Total number of pounds of taffy sold from each line, and total number of pounds sold overall
10. Profitability estimate for the day based on hourly wage for the 2 employees of $8.29/hour for 10 hours each, and a cost of materials of $3.49 per pound of taffy
