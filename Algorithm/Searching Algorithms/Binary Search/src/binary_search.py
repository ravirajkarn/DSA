def binary_search(list, item):
    low = 0 
    high = len(list) - 1
    num = (low + high) // 2
    mid = list[num]
    while low <= high and mid != item and item >= list[low] and item <= list[high]:
        if item >  mid:
            low = num + 1
        else:
            high = num 
        num = (low + high) // 2
        mid = list[num]
    if (mid == item):
        return num + 1
        
def main():
    number = [11, 12, 13, 14, 16, 17, 18, 19, 110, 111]
    item = 19
    print(f"the number is: {binary_search(number, item)}")

if __name__ == "__main__":
    main()