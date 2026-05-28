# This code is created by me
def selection_sort(nums):
    if len(nums) < 1:
        return nums
    for index in range(len(nums)):
        selected = index
        selector = index
        for selector in range(index + 1, len(nums)):
            if nums[selector] < nums[selected]:
                selected = selector
        if index != selected:
            nums[index], nums[selected] = nums[selected], nums[index]


def main():
    number = [64, 25, 12, 22, 11, -1, 0, 3, 5, 9, 12]
    selection_sort(number)
    print(f"the number is: {number}")


if __name__ == "__main__":
    main()
