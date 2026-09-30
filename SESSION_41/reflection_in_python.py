class MyMeta(type): 
    def __new__(self, cls_name, cls_bases, cls_dict): 
        print('cls_name:', cls_name)
        print("cls_attributes:")
        for (attr_name, attr_object) in cls_dict.items(): 
            print(f'{attr_name}:{type(attr_object)}')
        print("Base class list:")
        for cls in cls_bases:
            print(f'{cls.__name__}')
        return type.__new__(self, cls_name, cls_bases, cls_dict)

    def __call__(self, *args, **kwargs): 
        print("new object is being created")

class B1: 
    pass 

class B2: 
    pass 

class D(B1, B2, metaclass = MyMeta): 
    def __init__(self): 
        self.x = 10 

    def get_x(self): 
        return self.x 

    def set_x(self, new_x): 
        self.x = new_x 

    NUM = 500 
    L = [10 ,20, 30]

objD1 = D() 
objD2 = D() 

