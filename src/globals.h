extern int samples;
extern int cycle;
extern int readings; 
extern int NIR [250];
extern int RED [250];
extern float SaO2_array [250];

/*
Why do I use global variables?
Because I'm lazy.

Sorry, what I meant to say is,
"this is an embedded system and lots of normal rules of thumb
don't apply."

But mostly I'm lazy.
*/