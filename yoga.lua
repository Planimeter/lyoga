--=========== Copyright © 2019, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( "yoga.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "yoga" )
