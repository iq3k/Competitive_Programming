db TernarySearchF(db l, db r) {        
    while (r - l > 1e-9) {
        db m1 = l + (r - l) / 3;
		db m2 = r - (r - l) / 3;  
        if (f(m1) < f(m2))  
			r = m2;
        else 
        	l = m1;
    }
    return l;                    
}
