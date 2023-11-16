use crate::bytebufferext::{decode_impl, empty_impl, encode_impl};

#[derive(Copy, Clone, Default)]
pub struct Color3B {
    pub r: u8,
    pub g: u8,
    pub b: u8,
}

encode_impl!(Color3B, buf, self, {
    buf.write_u8(self.r);
    buf.write_u8(self.g);
    buf.write_u8(self.b);
});

empty_impl!(Color3B, Self::default());

decode_impl!(Color3B, buf, self, {
    self.r = buf.read_u8()?;
    self.g = buf.read_u8()?;
    self.b = buf.read_u8()?;
    Ok(())
});

#[derive(Copy, Clone, Default)]
pub struct Color4B {
    pub r: u8,
    pub g: u8,
    pub b: u8,
    pub a: u8,
}

encode_impl!(Color4B, buf, self, {
    buf.write_u8(self.r);
    buf.write_u8(self.g);
    buf.write_u8(self.b);
    buf.write_u8(self.a);
});

empty_impl!(Color4B, Self::default());

decode_impl!(Color4B, buf, self, {
    self.r = buf.read_u8()?;
    self.g = buf.read_u8()?;
    self.b = buf.read_u8()?;
    self.a = buf.read_u8()?;
    Ok(())
});

#[derive(Copy, Clone, Default)]
pub struct Point {
    pub x: f32,
    pub y: f32,
}

encode_impl!(Point, buf, self, {
    buf.write_f32(self.x);
    buf.write_f32(self.y);
});

empty_impl!(Point, Self::default());

decode_impl!(Point, buf, self, {
    self.x = buf.read_f32()?;
    self.y = buf.read_f32()?;
    Ok(())
});