{-# LANGUAGE ForeignFunctionInterface #-}

module FFItest where

import Foreign.C

foreign import ccall "testffi.h asd1" asd1 :: CInt -> IO ()
foreign import ccall "testffi.h asd2" asd2 :: CInt -> IO ()



