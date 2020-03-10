'''
Given an array of integers, find the maximum possible sum you can get form one of its contiguous subarrays. The subarray from wich this sum comes must contain a leat 1 element.

Example:
    For inputArray = [-2, 2, 5, -11, 6], the output should be arrayMaxConsecutiveSum(inputArray) = 7.
'''
def arrayMaxConsecutiveSum(inputArray):
    max_sum = inputArray[0]
    current_sum = max_sum

    for x in inputArray[1:]:
        current_sum = max(x, current_sum + x)
        max_sum = max(current_sum, max_sum)
    return max_sum
        