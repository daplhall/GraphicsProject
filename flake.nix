
{
	description = "C23 development environment";

	inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

	outputs = { self, nixpkgs }:
		let
		systems = [
			"x86_64-linux"
			#"aarch64-linux"
			#"x86_64-darwin"
			#"aarch64-darwin"
		];

		forAllSystems = nixpkgs.lib.genAttrs systems;
		in {
			devShells = forAllSystems (system:
			let
			  pkgs = nixpkgs.legacyPackages.${system};
			in
			{
			  default = pkgs.mkShell {
			    packages = with pkgs; [
			      gcc
			      clang
			      gnumake
			      gdb
			      clang-tools
			    ];
			  };
			});

			shellHook = ''
			export PS1="[C env] $PS1"
			Welcome to your C language dev enviromment 
			'';
		};
}
