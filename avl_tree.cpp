// avl trees  ==> |h2-h1|<=1  ==> ROTATION(imp.)
/*
    case: 01: [30, 40, 20, 35, 15]
                        30
                    20      40
                15      35

        HeightOfTree = 3
        Searching : 
            TimeComplexity = O(N)

============================

    case: 02: [15, 20, 30, 35, 40]
                        15
                            20
                                30
                                    35
                                        40
        HeightOfTree = 5
        Searching: 
            TimeComplexity = O(log(N))

============================


1. LEFT ROTATION: 

    ex: 01: x
                y
                    z
    
    sl: o1:     y
            x       z

----
    ex: 02:         x
                xL      y
                    yL      z
                        zL      zR

    sl: 02: 
                            y
                    x               z
                xL      YL      zL      zR

---

2. RIGHT ROTATION:  

    ex: 01:         x
                y
            z
    sl: 01:         y
                z       x
    
    ---

    ex: 02:                 x
                        y      xR
                    z       yR
                zL      zR
    
    sl: 02:                 y
                    z               x
                zL      zR      yR      xR


CASES OF ROTATION: 
    RR, LL, RL, LR

    case:01: RR: (Left rotation)
            i/p:
                    5
                        10
                            15
            o/p: 
                        10
                    5       15
    
    case: 02: LL:  (right rotation)
            i/p: 
                        15
                    10
                5
            
            o/p:        10
                    5       15
    
    case: 03: RL: (right rotation(lowerelement) + left rotation(lower_element))
            i/p: 
                    5
                        15(right rotation then left rotation)
                    10
            
            o/p:   
                    5
                        10
                            15 
            Now it becomes RR-case
    
    case: 04: LR: (left rotation(lower_element) +r right rotation(lower_element))
            i/p: 
                    15
                5
                    10
            
            o/p: 
                    15
                10
            5
            Now it comes LL-case

====
*/
