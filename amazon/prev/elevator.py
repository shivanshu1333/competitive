def canReach(start, target, up, down, total):
    dp = [False] * total
    stack = [start]

    while stack:
        node = stack.pop()

        if dp[node]:
            continue
        elif node == target:
            return True
        else:
            dp[node] = True
            if node + up < total + 1:
                stack.append(node + up)
            if node - down > 0:
                stack.append(node - down)

    return False

print(canReach(7, 9, 5, 3, 20))
print(canReach(13, 4, 2, 8, 20))