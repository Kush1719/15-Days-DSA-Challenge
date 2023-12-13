void mergeSort(vector < int > & arr, int n) {
    int currentGap = 2;
    float nearestPowerTwo = log2(n);
    if (int(nearestPowerTwo) != (nearestPowerTwo)) {
        nearestPowerTwo = pow(2, int(nearestPowerTwo) + 1);
    } 
    else {
        nearestPowerTwo = pow(2, int(nearestPowerTwo));
    }
    int parts;
    while (currentGap <= nearestPowerTwo) {
        parts = n / currentGap;
        if (n % currentGap != 0) {
            parts++;
        }
        for (int i = 0; i < parts; i++) {
            int ptrLeft = i * currentGap;
            int copyLeft = ptrLeft;
            int end = (i + 1) * currentGap;
            int ptrRight = (ptrLeft + end) / 2;
            end = min(end, n);
            int copyRight = ptrRight;
            vector < int > mergeArr;
            while (ptrLeft <= copyRight and ptrRight < end) {
                if (arr[ptrLeft] > arr[ptrRight]) {
                    mergeArr.push_back(arr[ptrRight]);
                    ptrRight += 1;
                } else {
                    mergeArr.push_back(arr[ptrLeft]);
                    ptrLeft += 1;
                }
                if (ptrLeft == copyRight) {
                    while (ptrRight != end) {
                        mergeArr.push_back(arr[ptrRight]);
                        ptrRight++;
                    }
                    break;
                }
                if (ptrRight == end) {
                    while (ptrLeft != copyRight) {
                        mergeArr.push_back(arr[ptrLeft]);
                        ptrLeft++;
                    }
                    break;
                }
            }
            for (int i = 0; i < mergeArr.size(); i++) {
                arr[copyLeft + i] = mergeArr[i];
            }
        }
        currentGap *= 2;
    }
}