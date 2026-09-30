 if(typeid(*pB) == typeid(D1))
        dynamic_cast<D1*>(pB)->g1(); 
    else if(typeid(*pB) == typeid(D2))
        dynamic_cast<D2*>(pB)->g2(); 
    else if(typeid(*pB) == typeid(D3)) 
        dynamic_cast<D3*>(pB)->g3(); 