# This code is created by me
def binary_search(nums, target):
    low = 0 
    high = len(nums) - 1
    num = low + (high - low) // 2
    mid = nums[num]
    while low <= high and target >= nums[low] and target <= nums[high]:
        if mid != target:
            if mid <= target:
                low = num
            else:
                high = mid
            num = num = low + (high - low) // 2
            mid = nums[num]
            if nums[low] == target: return low
            if nums[high] == target: return high
            if low == mid: break
        else:
            return mid
    return -1
        
def main():
    number = [11, 12, 13, 14, 16, 17, 18, 19, 110, 111]
    target = 0
    print(f"the number is: {binary_search(number, target)}")

if __name__ == "__main__":
    main()