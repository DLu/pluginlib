
from ros2cli.verb import VerbExtension

from ros2plugincli.api import list_the_plugins


class ListVerb(VerbExtension):
    def add_arguments(self, parser, cli_name):
        pass
        # parser.add_argument(
        #        '--simple', '-s', action='store_true',
        #       help="Display the message in a simple form.")

    def main(self, *, args):
        print(list_the_plugins())
