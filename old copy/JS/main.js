function maxConsectiveOne(arr){
    let maxCount =0  , count = 0 ;
    for ( let i = 0; i < arr.length ; i ++
    )  {
        if ( arr[i] ==1){
            count++;
            maxCount = Math.max(maxCount, count) ; 
        }
        else {
            count = 0; 
        }

    }
    return maxCount ; 
    
}

let arr = [1, 1 , 0, 0, 1, 1,1] ;
console.log(maxConsectiveOne(arr)); 