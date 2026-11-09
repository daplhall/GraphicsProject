{
  description = "C development environment";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }: 
	let
		system = "x86_64-linux";
	in {
		devShells.${system}.default =
		let
			pkgs = import nixpkgs {
				inherit system;
			};
		in
			pkgs.mkShell {
				packages = with pkgs; [
					gcc
					clang
					ninja
					cmake
					gdb
					clang-tools
					sdl3
					gtest
				];

		shellHook = ''
			export PS1="[C dev env] $PS1"
			echo "Welcome to your C development environment!"
		'';
	};
  };
}
