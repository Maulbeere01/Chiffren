#include <stdio.h>
#include <string.h>
#include "Encryption.h"
#include "VigenereEncryption.h"
#include "Häufigkeitsanalyse.h"
#include "Decryption.h"
#include "Kasiski_Test.h"

// fuer linux:  git config --global core.autocrlf input

int main() {
    /*
        int shiftValue = 22;
        char text[] = "Mein bester Freund die Ente";
        CaeserChiffreEncryption(text, shiftValue);
        printf("Geheim Text:\n%s\n\n", text);

        int decryptedShiftValue = frequencyAnalysis(text);

        CaeserChiffreDecryption(text, decryptedShiftValue); */

    char VigenereText[] = "the history of human civilization is a tapestry woven from countless threads of discovery, innovation, conflict, and cooperation. from the earliest days of hunter-gatherer societies, humanity has shown a relentless drive to adapt, improve, and overcome the challenges posed by nature and by its own complexities. this narrative, rich and multifaceted, provides insights into not only where we have come from but also the trajectories we might follow in the future.prehistoric humans relied on their keen observational skills and communal efforts to survive. the development of tools marked a pivotal step forward, enabling our ancestors to hunt more effectively, process food more efficiently, and construct rudimentary shelters. the mastery of fire, perhaps one of the most transformative technologies of all time, not only provided warmth and protection but also expanded the range of edible foods through cooking. this simple act of harnessing fire set the stage for a cascade of advancements that would shape the course of history.as human societies grew, so did the need for organization and communication. early agricultural practices, emerging around 10,000 years ago, necessitated the development of stable settlements. with these settlements came the first inklings of governance, division of labor, and written language. the sumerians, in the fertile crescent, are credited with inventing one of the earliest known writing systems, cuneiform, which was used for everything from recording transactions to documenting religious practices. writing allowed knowledge to be preserved and shared across generations, fueling the exponential growth of civilizations.the rise and fall of empires—from egyptian dynasties to the roman republic, from the gupta empire in india to the tang dynasty in china—showcases humanity's capacity for both creation and destruction. empires often pushed the boundaries of what was technologically and culturally possible, advancing fields such as architecture, philosophy, science, and art. however, they were also fraught with exploitation, inequality, and internal strife, often leading to their eventual decline. the lessons drawn from these cycles are timeless: power is fleeting, and hubris can be a civilization's undoing.the renaissance, spanning roughly the 14th to 17th centuries, marked a rebirth of interest in the classical knowledge of ancient greece and rome. this period saw extraordinary achievements in art, literature, and science, driven by figures such as leonardo da vinci, michelangelo, and galileo galilei. the printing press, invented by johannes gutenberg in the mid-15th century, democratized knowledge in an unprecedented way, making books more accessible and ideas easier to disseminate.the enlightenment of the 18th century built upon these foundations, emphasizing reason, skepticism of dogma, and the pursuit of scientific inquiry. thinkers like voltaire, john locke, and immanuel kant challenged established norms and laid the groundwork for modern democratic ideals. these intellectual currents profoundly influenced subsequent revolutions, including the american and french revolutions, which sought to enshrine principles of liberty and equality in governance.the industrial revolution of the 19th century was a watershed moment in human history. steam power, mechanization, and the rise of factories transformed economies and societies, shifting populations from rural areas to burgeoning urban centers. while this period brought immense technological progress, it also highlighted stark inequalities and environmental degradation. the writings of karl marx and others critiqued the exploitative nature of unchecked capitalism, planting the seeds for labor movements and socialist ideologies.now, in the 21st century, humanity faces a host of unprecedented challenges: climate change, geopolitical tensions, pandemics, and the ethical dilemmas posed by artificial intelligence. yet, the same qualities that have driven human progress—curiosity, resilience, and the capacity for collaboration—offer hope for addressing these issues. the interconnected world of today requires an equally interconnected approach to problem-solving, transcending national borders and ideological divides.in reflecting on this journey, one cannot help but marvel at the sheer scope of human achievement and the resilience displayed in the face of adversity. while the future remains uncertain, the lessons of the past serve as both a guide and a cautionary tale. humanity's story is still being written, and the next chapters will depend on the choices we make today.";
    // waehle einen schluessel laenger als 2
    char secretKey[] = "lololo";
   
    VigenereEncryption(VigenereText, secretKey);

    kasiski_test(VigenereText);

}






