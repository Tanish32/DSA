def square_root(number):
    left = 0
    right = number
    while left <= right:
        mid = (left + right) // 2
        if mid * mid <= number < (mid + 1) * (mid + 1):
            return mid
        elif number < mid * mid:
            right = mid - 1
        else:
            left = mid + 1
