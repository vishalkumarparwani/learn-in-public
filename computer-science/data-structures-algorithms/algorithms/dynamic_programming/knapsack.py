def knapsack_brute_force(weights, values, capacity, i=0):
    if i == len(weights):
        return 0

    skip = knapsack_brute_force(weights, values, capacity, i + 1)
