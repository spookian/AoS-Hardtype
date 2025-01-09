def color_to_gbabgr(color : int):
    red = ((color >> 16) // 8)
    green = (((color >> 8) & 0x00FF) // 8) << 5
    blue = ((color & 0xFF) // 8) << 10
    return red + green + blue

def gbabgr_to_color(bgr):
    red =  ((bgr & 31) * 8) << 16
    green = (((bgr & 0x3E0) >> 5) * 8) << 8 
    blue = (((bgr & 0x7C00) >> 10) * 8) 
    return red + green + blue
    
print( hex( color_to_gbabgr(0x0073ff) ) )
