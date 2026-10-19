def knapsack(values, weights, W):
    n = len(values)
    V = []

    for i in range(n + 1):
        V.append([0] * (W + 1))

    for i in range(1, n + 1):
        for w in range(W + 1):
            if weights[i - 1] <= w:
                V[i][w] = max(V[i - 1][w], V[i - 1][w - weights[i - 1]] + values[i - 1])
            else:
                V[i][w] = V[i - 1][w]
    return V


def chosen_items(V, weights, W):
    items = []
    w = W
    for i in range(len(weights), 0, -1):
        if V[i][w] != V[i - 1][w]:
            items.append(i - 1)
            w -= weights[i - 1]
    items.reverse()
    return items


def print_table(V):
    for row in V:
        for cell in row:
            print(cell, end=" ")
        print()


if __name__ == "__main__":
    values = [3, 4, 5]
    weights = [2, 3, 4]
    W = 5
    V = knapsack(values, weights, W)
    print_table(V)
    assert V[3][5] == 7
    assert chosen_items(V, weights, W) == [0, 1]
    print("All checks passed")