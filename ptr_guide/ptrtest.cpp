struct coord
{
   int x;
   int y;
   int z;
};

void ptrtest()
{
   coord *coordptr;
   coord **cptr_ptr = &coordptr;

   (*cptr_ptr)->x = 2;
   // (**cptr_ptr).x = 10; same as above

   return;
}

// single ptr c style
void ptrtest_single_c(coord *coordptr)
{
   if (coordptr)
   {
      coordptr->x = 20; // This works! main's myCoord1.x changes.
   }
}

// single ptr c++ style
void ptrtest_single_cpp(coord &coordptr)
{
   coordptr.x = 30; // Direct access, no arrows needed!
}

// 1. Pass by Double Pointer (The "C-Style" way used in your server)
void ptrtest_double_c(coord **coordptr_ptr)
{
   if (coordptr_ptr && *coordptr_ptr)
   {
      (*coordptr_ptr)->x = 5;
   }
}

// 2. Pass by Pointer Reference (The "Modern C++" way)
// This allows you to modify the pointer itself without the ** syntax
void ptrtest_double_cpp(coord *&coordptr_ptr)
{
   if (coordptr_ptr)
   {
      coordptr_ptr->x = 7;
   }
}

// change which coord the coordptr points to c style
// this is done by passing in the ptr to the coord ptr, what the coordptr points to
void changeCoordPtr_c(coord **coordptr_ptr, coord &coordstruct)
{
   *coordptr_ptr = &coordstruct;
   (*coordptr_ptr)->y = 5;
}

// change which coord the coordptr points to c++ style
// this is done by passing in the coordptr, then changing what it points to to the new coord
void changeCoordPtr_cpp(coord *&coordptr, coord &coordstruct)
{
   coordptr = &coordstruct;
   coordptr->y = 5;
}

int main()
{
   // FIX: Allocate actual memory so we don't crash
   coord myCoord1 = {0, 0, 0};
   coord myCoord2 = {0, 0, 0};
   coord *coordptr = &myCoord1;
   coord **cptr_ptr = &coordptr;

   // These are now safe because coordptr points to myCoord
   (*cptr_ptr)->x = 10;

   ptrtest_single_c(coordptr);
   ptrtest_single_cpp(myCoord1);
   // this is the way to do it in c
   ptrtest_double_c(cptr_ptr); // Calls the double pointer version

   // this is the way to do it in c++
   ptrtest_double_cpp(coordptr); // Calls the pointer reference version

   // changing the coord that coordptr points to
   changeCoordPtr_c(cptr_ptr, myCoord2);
   changeCoordPtr_cpp(coordptr, myCoord1);

   return 0;
}