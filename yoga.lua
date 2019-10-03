--=========== Copyright © 2019, Planimeter, All rights reserved. =============--
--
-- Purpose:
--
--============================================================================--

local ffi = require( "ffi" )
io.input( "Yoga.h" )
ffi.cdef( io.read( "*all" ) )
return ffi.load( "yogacore" )
