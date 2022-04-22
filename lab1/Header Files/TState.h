#ifndef TSTATE_H
#define TSTATE_H

enum class State
{
    Standing0,  // standing on zero floor
    Going_Up0,  // going from zero floor to first floor

    Standing1,      // standing on first floor
    Going_Up1,      // going from first floor to second
    Going_Down1,    // going from first floor to zero floor
    
	Standing2,
    Going_Up2,
    Going_Down2,
    
	Standing3,
    Going_Up3,
    Going_Down3,
    
	Standing4,
    Going_Up4,
    Going_Down4,
    
	Standing5,
    Going_Up5,
    Going_Down5,
    
	Standing6,
    Going_Up6,
    Going_Down6,
    
	Standing7,
    Going_Up7,
    Going_Down7,
    
	Standing8,
    Going_Up8,
    Going_Down8,
    
	Standing9,
    Going_Down9,
    
    Final
};

#endif