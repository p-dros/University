/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _ADD_H_RPCGEN
#define _ADD_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAXNAMELEN 255

typedef int integer;

typedef char *filename;

struct point {
	integer x;
	integer y;
};
typedef struct point point;

struct shape {
	integer type;
	union {
		integer square_side;
		integer circle_radius;
	} shape_u;
};
typedef struct shape shape;

typedef point point2d;

typedef struct {
	u_int point3d_len;
	point2d *point3d_val;
} point3d;

typedef char *filename_list;

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_integer (XDR *, integer*);
extern  bool_t xdr_filename (XDR *, filename*);
extern  bool_t xdr_point (XDR *, point*);
extern  bool_t xdr_shape (XDR *, shape*);
extern  bool_t xdr_point2d (XDR *, point2d*);
extern  bool_t xdr_point3d (XDR *, point3d*);
extern  bool_t xdr_filename_list (XDR *, filename_list*);

#else /* K&R C */
extern bool_t xdr_integer ();
extern bool_t xdr_filename ();
extern bool_t xdr_point ();
extern bool_t xdr_shape ();
extern bool_t xdr_point2d ();
extern bool_t xdr_point3d ();
extern bool_t xdr_filename_list ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_ADD_H_RPCGEN */
