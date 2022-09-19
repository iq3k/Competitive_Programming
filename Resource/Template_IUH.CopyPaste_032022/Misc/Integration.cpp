db integration(db a, db b){
	ll step = 1000000; // multiplied by 2
    db h = (b - a) / step;
    db s = f(a) + f(b);
    for (int i = 1; i <= step - 1; ++i) {
        db x = a + h * i;
        s += f(x) * ((i & 1) ? 4 : 2);
    }
    s *= h / 3;
    return s;
}
