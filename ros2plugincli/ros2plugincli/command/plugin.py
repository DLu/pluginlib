from ros2cli.command import CommandExtension
from ros2cli.command import add_subparsers
from ros2cli.verb import get_verb_extensions


class PluginCommand(CommandExtension):
    def add_arguments(self, parser, cli_name):
        self._subparser = parser
        # get verb extensions and let them add their arguments
        verb_extensions = get_verb_extensions('ros2plugincli.verb')
        add_subparsers(
            parser, cli_name, '_verb', verb_extensions, required=False)

    def main(self, *, parser, args):
        if not hasattr(args, '_verb'):
            # in case no verb was passed
            self._subparser.print_help()
            return 0

        extension = getattr(args, '_verb')

        # call the verb's main method
        return extension.main(args=args)
