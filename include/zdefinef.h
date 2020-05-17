/*
** EPITECH PROJECT, 2020
** color_defines.h
** File description:
** set colors to my_printf
*/

#ifndef THE_DEFINEF
#define THE_DEFINEF

/*-------------------------------*/
/*                               */
/*              STYLE            */
/*                               */
/*-------------------------------*/

// text_style
#define DEF      "\e[m"  //couleur par defaut
#define BOLD     "\e[1m" //gras
#define DARK     "\e[2m" //sombre
#define ITA      "\e[3m" //italique
#define UNDER    "\e[4m" //souligné
#define BLINK    "\e[6m" //clignote
#define FBG      "\e[7m" //inverse foregroud et background
#define INVI     "\e[8m" //invisible
#define STRIKE   "\e[9m" //barré
// !test_style

/*-------------------------------*/
/*                               */
/*              COLOR            */
/*                               */
/*-------------------------------*/

/*******FOREGROUND*******/

// text_color
#define BLACK    "\e[30m"
#define RED      "\e[31m"
#define GREEN    "\e[32m"
#define YELLOW   "\e[33m"
#define BLUE     "\e[34m"
#define MAGENTA  "\e[35m"
#define TEAL     "\e[36m"
#define WHITE    "\e[37m"
// !text_color

// text_light_color
#define LBLACK   "\e[90m"
#define LRED     "\e[91m"
#define LGREEN   "\e[92m"
#define LYELLOW  "\e[93m"
#define LBLUE    "\e[94m"
#define LMAGENTA "\e[95m"
#define LTEAL    "\e[96m"
#define LWHITE   "\e[97m"
// !text_light_color

/*******BACKGROUND*******/

// text_color
#define BGBLACK    "\e[40m"
#define BGRED      "\e[41m"
#define BGGREEN    "\e[42m"
#define BGYELLOW   "\e[43m"
#define BGBLUE     "\e[44m"
#define BGMAGENTA  "\e[45m"
#define BGTEAL     "\e[46m"
#define BGWHITE    "\e[47m"
// !text_color

// text_light_color
#define BGLBLACK   "\e[100m"
#define BGLRED     "\e[101m"
#define BGLGREEN   "\e[102m"
#define BGLYELLOW  "\e[103m"
#define BGLBLUE    "\e[104m"
#define BGLMAGENTA "\e[105m"
#define BGLTEAL    "\e[106m"
#define BGLWHITE   "\e[107m"
// !text_light_color

/*-------------------------------*/
/*                               */
/*             PRINTF            */
/*                               */
/*-------------------------------*/

/*-._.-*°`°*-._ TOOLS _.-*°`°*-._.-*/

#define CLEAR     my_printf(2, "\e[H")
#define CLEAR_ALL my_printf(2, "\e[H\e[J")

#define F16(a)    ((a < 16) ? "0" : "")
#define F256(a)   ((a < 16) ? "00" :
((a < 256) ? "0" : ""))
#define F65536(a) ((a < 16) ? "000" :
((a < 256) ? "00" : ((a < 65536) ? "0" : "")))
#define F10(a)    ((a < 10) ? "0" : "")
#define F100(a)   ((a < 10) ? "00" :
((a < 100) ? "0" : ""))
#define F1000(a)  ((a < 10) ? "000" :
((a < 100) ? "00" : ((a < 1000) ? "0" : "")))

/*|||||| NORMAL MODE ||||||*/

/***********DARK***********/

// putstr_color
#define SBLACK   "\e[30m%s\e[m"
#define SRED     "\e[31m%s\e[m"
#define SGREEN   "\e[32m%s\e[m"
#define SYELLOW  "\e[33m%s\e[m"
#define SBLUE    "\e[34m%s\e[m"
#define SMAGENTA "\e[35m%s\e[m"
#define STEAL    "\e[36m%s\e[m"
#define SWHITE   "\e[37m%s\e[m"
// !putstr_color

// putnbr_color
#define DBLACK   "\e[30m%d\e[m"
#define DRED     "\e[31m%d\e[m"
#define DGREEN   "\e[32m%d\e[m"
#define DYELLOW  "\e[33m%d\e[m"
#define DBLUE    "\e[34m%d\e[m"
#define DMAGENTA "\e[35m%d\e[m"
#define DTEAL    "\e[36m%d\e[m"
#define DWHITE   "\e[37m%d\e[m"
// !putnbr_color

// putchar_color
#define CBLACK   "\e[30m%c\e[m"
#define CRED     "\e[31m%c\e[m"
#define CGREEN   "\e[32m%c\e[m"
#define CYELLOW  "\e[33m%c\e[m"
#define CBLUE    "\e[34m%c\e[m"
#define CMAGENTA "\e[35m%c\e[m"
#define CTEAL    "\e[36m%c\e[m"
#define CWHITE   "\e[37m%c\e[m"
// !putchar_color

// puthexa_color
#define XBLACK   "\e[30m%x\e[m"
#define XRED     "\e[31m%x\e[m"
#define XGREEN   "\e[32m%x\e[m"
#define XYELLOW  "\e[33m%x\e[m"
#define XBLUE    "\e[34m%x\e[m"
#define XMAGENTA "\e[35m%x\e[m"
#define XTEAL    "\e[36m%x\e[m"
#define XWHITE   "\e[37m%x\e[m"
// !puthexa_color

// putstrnbr_color
#define SDBLACK   "\e[30m%s%d\e[m"
#define SDRED     "\e[31m%s%d\e[m"
#define SDGREEN   "\e[32m%s%d\e[m"
#define SDYELLOW  "\e[33m%s%d\e[m"
#define SDBLUE    "\e[34m%s%d\e[m"
#define SDMAGENTA "\e[35m%s%d\e[m"
#define SDTEAL    "\e[36m%s%d\e[m"
#define SDWHITE   "\e[37m%s%d\e[m"
// !putstrnbr_color

// putstrnbr_color
#define SXBLACK   "\e[30m%s%x\e[m"
#define SXRED     "\e[31m%s%x\e[m"
#define SXGREEN   "\e[32m%s%x\e[m"
#define SXYELLOW  "\e[33m%s%x\e[m"
#define SXBLUE    "\e[34m%s%x\e[m"
#define SXMAGENTA "\e[35m%s%x\e[m"
#define SXTEAL    "\e[36m%s%x\e[m"
#define SXWHITE   "\e[37m%s%x\e[m"
// !putstrnbr_color

/***********LIGHT***********/

// putstr_light_color
#define SLBLACK   "\e[90m%s\e[m"
#define SLRED     "\e[91m%s\e[m"
#define SLGREEN   "\e[92m%s\e[m"
#define SLYELLOW  "\e[93m%s\e[m"
#define SLBLUE    "\e[94m%s\e[m"
#define SLMAGENTA "\e[95m%s\e[m"
#define SLTEAL    "\e[96m%s\e[m"
#define SLWHITE   "\e[97m%s\e[m"
// !putstr_light_color

// putnbr_light_color
#define DLBLACK   "\e[90m%d\e[m"
#define DLRED     "\e[91m%d\e[m"
#define DLGREEN   "\e[92m%d\e[m"
#define DLYELLOW  "\e[93m%d\e[m"
#define DLBLUE    "\e[94m%d\e[m"
#define DLMAGENTA "\e[95m%d\e[m"
#define DLTEAL    "\e[96m%d\e[m"
#define DLWHITE   "\e[97m%d\e[m"
// !putnbr_light_color

// putchar_light_color
#define CLBLACK   "\e[90m%c\e[m"
#define CLRED     "\e[91m%c\e[m"
#define CLGREEN   "\e[92m%c\e[m"
#define CLYELLOW  "\e[93m%c\e[m"
#define CLBLUE    "\e[94m%c\e[m"
#define CLMAGENTA "\e[95m%c\e[m"
#define CLTEAL    "\e[96m%c\e[m"
#define CLWHITE   "\e[97m%c\e[m"
// !putchar_light_color

// puthexa_light_color
#define XLBLACK   "\e[90m%x\e[m"
#define XLRED     "\e[91m%x\e[m"
#define XLGREEN   "\e[92m%x\e[m"
#define XLYELLOW  "\e[93m%x\e[m"
#define XLBLUE    "\e[94m%x\e[m"
#define XLMAGENTA "\e[95m%x\e[m"
#define XLTEAL    "\e[96m%x\e[m"
#define XLWHITE   "\e[97m%x\e[m"
// !puthexa_light_color

// puthexa_light_color
#define SDLBLACK   "\e[90m%s%d\e[m"
#define SDLRED     "\e[91m%s%d\e[m"
#define SDLGREEN   "\e[92m%s%d\e[m"
#define SDLYELLOW  "\e[93m%s%d\e[m"
#define SDLBLUE    "\e[94m%s%d\e[m"
#define SDLMAGENTA "\e[95m%s%d\e[m"
#define SDLTEAL    "\e[96m%s%d\e[m"
#define SDLWHITE   "\e[97m%s%d\e[m"
// !puthexa_light_color

// puthexa_light_color
#define SXLBLACK   "\e[90m%s%x\e[m"
#define SXLRED     "\e[91m%s%x\e[m"
#define SXLGREEN   "\e[92m%s%x\e[m"
#define SXLYELLOW  "\e[93m%s%x\e[m"
#define SXLBLUE    "\e[94m%s%x\e[m"
#define SXLMAGENTA "\e[95m%s%x\e[m"
#define SXLTEAL    "\e[96m%s%x\e[m"
#define SXLWHITE   "\e[97m%s%x\e[m"
// !puthexa_light_color

/*||||| CHARIOT MODE ||||||*/

/***********DARK***********/

// putstr_color_\n
#define SBLACKN   "\e[30m%s\e[m\n"
#define SREDN     "\e[31m%s\e[m\n"
#define SGREENN   "\e[32m%s\e[m\n"
#define SYELLOWN  "\e[33m%s\e[m\n"
#define SBLUEN    "\e[34m%s\e[m\n"
#define SMAGENTAN "\e[35m%s\e[m\n"
#define STEALN    "\e[36m%s\e[m\n"
#define SWHITEN   "\e[37m%s\e[m\n"
// !putstr_color_\n

// putnbr_color_\n
#define DBLACKN   "\e[30m%d\e[m\n"
#define DREDN     "\e[31m%d\e[m\n"
#define DGREENN   "\e[32m%d\e[m\n"
#define DYELLOWN  "\e[33m%d\e[m\n"
#define DBLUEN    "\e[34m%d\e[m\n"
#define DMAGENTAN "\e[35m%d\e[m\n"
#define DTEALN    "\e[36m%d\e[m\n"
#define DWHITEN   "\e[37m%d\e[m\n"
// !putnbr_color_\n

// putchar_color_\n
#define CBLACKN   "\e[30m%c\e[m\n"
#define CREDN     "\e[31m%c\e[m\n"
#define CGREENN   "\e[32m%c\e[m\n"
#define CYELLOWN  "\e[33m%c\e[m\n"
#define CBLUEN    "\e[34m%c\e[m\n"
#define CMAGENTAN "\e[35m%c\e[m\n"
#define CTEALN    "\e[36m%c\e[m\n"
#define CWHITEN   "\e[37m%c\e[m\n"
// !putchar_color_\n

// puthexa_color_\n
#define XBLACKN   "\e[30m%x\e[m\n"
#define XREDN     "\e[31m%x\e[m\n"
#define XGREENN   "\e[32m%x\e[m\n"
#define XYELLOWN  "\e[33m%x\e[m\n"
#define XBLUEN    "\e[34m%x\e[m\n"
#define XMAGENTAN "\e[35m%x\e[m\n"
#define XTEALN    "\e[36m%x\e[m\n"
#define XWHITEN   "\e[37m%x\e[m\n"
// !puthexa_color_\n

// putstrnbr_color_\n
#define SDBLACKN   "\e[30m%s%d\e[m\n"
#define SDREDN     "\e[31m%s%d\e[m\n"
#define SDGREENN   "\e[32m%s%d\e[m\n"
#define SDYELLOWN  "\e[33m%s%d\e[m\n"
#define SDBLUEN    "\e[34m%s%d\e[m\n"
#define SDMAGENTAN "\e[35m%s%d\e[m\n"
#define SDTEALN    "\e[36m%s%d\e[m\n"
#define SDWHITEN   "\e[37m%s%d\e[m\n"
// !putstrnbr_color_\n

// putstrnbr_color_\n
#define SXBLACKN   "\e[30m%s%x\e[m\n"
#define SXREDN     "\e[31m%s%x\e[m\n"
#define SXGREENN   "\e[32m%s%x\e[m\n"
#define SXYELLOWN  "\e[33m%s%x\e[m\n"
#define SXBLUEN    "\e[34m%s%x\e[m\n"
#define SXMAGENTAN "\e[35m%s%x\e[m\n"
#define SXTEALN    "\e[36m%s%x\e[m\n"
#define SXWHITEN   "\e[37m%s%x\e[m\n"
// !putstrnbr_color_\n

/***********LIGHT***********/

// putstr_light_color_\n
#define SLBLACKN   "\e[90m%s\e[m\n"
#define SLREDN     "\e[91m%s\e[m\n"
#define SLGREENN   "\e[92m%s\e[m\n"
#define SLYELLOWN  "\e[93m%s\e[m\n"
#define SLBLUEN    "\e[94m%s\e[m\n"
#define SLMAGENTAN "\e[95m%s\e[m\n"
#define SLTEALN    "\e[96m%s\e[m\n"
#define SLWHITEN   "\e[97m%s\e[m\n"
// !putstr_light_color_\n

// putnbr_light_color_\n
#define DLBLACKN   "\e[90m%d\e[m\n"
#define DLREDN     "\e[91m%d\e[m\n"
#define DLGREENN   "\e[92m%d\e[m\n"
#define DLYELLOWN  "\e[93m%d\e[m\n"
#define DLBLUEN    "\e[94m%d\e[m\n"
#define DLMAGENTAN "\e[95m%d\e[m\n"
#define DLTEALN    "\e[96m%d\e[m\n"
#define DLWHITEN   "\e[97m%d\e[m\n"
// !putnbr_light_color_\n

// putchar_light_color_\n
#define CLBLACKN   "\e[90m%c\e[m\n"
#define CLREDN     "\e[91m%c\e[m\n"
#define CLGREENN   "\e[92m%c\e[m\n"
#define CLYELLOWN  "\e[93m%c\e[m\n"
#define CLBLUEN    "\e[94m%c\e[m\n"
#define CLMAGENTAN "\e[95m%c\e[m\n"
#define CLTEALN    "\e[96m%c\e[m\n"
#define CLWHITEN   "\e[97m%c\e[m\n"
// !putchar_light_color_\n

// puthexa_light_color_\n
#define XLBLACKN   "\e[90m%x\e[m\n"
#define XLREDN     "\e[91m%x\e[m\n"
#define XLGREENN   "\e[92m%x\e[m\n"
#define XLYELLOWN  "\e[93m%x\e[m\n"
#define XLBLUEN    "\e[94m%x\e[m\n"
#define XLMAGENTAN "\e[95m%x\e[m\n"
#define XLTEALN    "\e[96m%x\e[m\n"
#define XLWHITEN   "\e[97m%x\e[m\n"
// !puthexa_light_color_\n

// puthexa_light_color_\n
#define SDLBLACKN   "\e[90m%s%d\e[m\n"
#define SDLREDN     "\e[91m%s%d\e[m\n"
#define SDLGREENN   "\e[92m%s%d\e[m\n"
#define SDLYELLOWN  "\e[93m%s%d\e[m\n"
#define SDLBLUEN    "\e[94m%s%d\e[m\n"
#define SDLMAGENTAN "\e[95m%s%d\e[m\n"
#define SDLTEALN    "\e[96m%s%d\e[m\n"
#define SDLWHITEN   "\e[97m%s%d\e[m\n"
// !puthexa_light_color_\n

// puthexa_light_color_\n
#define SXLBLACKN   "\e[90m%s%x\e[m\n"
#define SXLREDN     "\e[91m%s%x\e[m\n"
#define SXLGREENN   "\e[92m%s%x\e[m\n"
#define SXLYELLOWN  "\e[93m%s%x\e[m\n"
#define SXLBLUEN    "\e[94m%s%x\e[m\n"
#define SXLMAGENTAN "\e[95m%s%x\e[m\n"
#define SXLTEALN    "\e[96m%s%x\e[m\n"
#define SXLWHITEN   "\e[97m%s%x\e[m\n"
// !puthexa_light_color_\n

#endif /* !THE_DEFINEF */
