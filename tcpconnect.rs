use std::

{ net::

{SocketAddr, TcpStream}
,
time::Duration,
};

fn main() {
let sock_addr: SocketAddr = std::env::args()
.into_iter()
.nth(1)
.unwrap()
.parse()
.unwrap();
dbg!(sock_addr);
let timeout = Duration::from_secs(5);
let maybe_stream = TcpStream::connect_timeout(&sock_addr, timeout);
match maybe_stream {
Ok(_stream) =>

{ println!("Successfully connected to server"); }
Err(err) =>

{ eprintln!("Failed to connect to server:
{:?}

", err);
}
};
}